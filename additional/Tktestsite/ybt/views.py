# -*- coding: utf-8 -*-
# 我们应每次都给成功的POST请求做重定向。 这就是web开发的最佳实践。

from django.http import HttpResponse
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.shortcuts import render_to_response

from django.template import RequestContext
from django.views.decorators.csrf import csrf_protect
import os
import thread

from YBT import manager
from ybt.forms import ContactForm
from ybt.forms import SearchForm

from django.http import StreamingHttpResponse

global RunningNo
RunningNo = []

global workspace
workspace = "F:/code/django/Tktestsite/ybt/files/"

@csrf_protect
def ybt(request):
    error = False
    running = False
    if 'workNo' in request.POST:
        # request信息带有POST数据
        filePath = "F:/code/django/Tktestsite/ybt/files/"
        # 参数
        workNo = request.POST.get('workNo', 'unknown')
        sheetName = request.POST.get('sheetName', 'unknown')
        startRow = request.POST.get('startRow', 'unknown')
        endRow = request.POST.get('endRow', 'unknown')
        outCol = request.POST.get('col', 'unknown')
        # 文件
        excelFile = request.FILES.get("excelFile", None)
        ssFile = request.FILES.get("ssFile", None)
        
        # 创建文件夹
        workspace = filePath + workNo
        if not os.path.exists(workspace):
            os.mkdir(workspace)
            if not os.path.exists(workspace+"/input/"):
                os.mkdir(workspace+"/input/")
        
        ssModel = None
        cbModel = None
        
        # 保证输入的参数表不为空
        if excelFile == None:
            error = True
        else:
            # 判断是否同一个任务正在执行
            if workNo in RunningNo:
                running = True
                return render_to_response("ybt.html", RequestContext(request, {'running': running}))

            with open(workspace + "/input/" + excelFile.name, "wb+") as f:
                for chunk in excelFile.chunks():
                    f.write(chunk)
            if ssFile != None:
                ssModel = workspace + "/input/" + ssFile.name     
                with open(workspace + "/input/" + ssFile.name, "wb+") as f:
                    for chunk in ssFile.chunks():
                        f.write(chunk)
            else:
                ssModel = None
            
            # 非所有险种必需
            cbFile = request.FILES.get("cbFile", None)
            if cbFile != None:
                cbModel = workspace + "/input/" + cbFile.name
                with open(workspace + "/input/" + cbFile.name, "wb+") as f:
                    for chunk in cbFile.chunks():
                        f.write(chunk)
            else:
                cbModel = None
    
            # 银行
            bankNo = request.POST.get('bankNo', None)
            
            # 执行逻辑代码
            excelPath = workspace + "/input/" + excelFile.name
    
            try:
                thread.start_new_thread(thrd_run, (excelPath, sheetName, ssModel, cbModel, workNo, bankNo, startRow, endRow, outCol))
            except:
                print "Error: unable to start thread!"
            
            return render_to_response("ybt_.html")
    return render_to_response("ybt.html", RequestContext(request, {'error': error}))
            
def thrd_run(excelPath, sheetName, ssModel, cbModel, workNo, bankNo, startRow, endRow, outCol):
    RunningNo.append(workNo)
    mgr = manager.Manager(excelPath, sheetName, ssModel, cbModel, workNo, bankNo, startRow, endRow, outCol)
    mgr.run()
    RunningNo.remove(workNo)

def search(request):
    """
    表单查询
    """
    if request.method == 'POST':
        form = SearchForm(request.POST)
        if form.is_valid():
            cd = form.cleaned_data
            # TODO List
            # return HttpResponseRedirect('/ybt/')
            if os.path.exists(workspace+cd['workNo']):
                files = []
                for subdir in os.listdir(workspace+cd['workNo']):
                    if subdir.find("zip") != -1:
                        files.append(subdir)
                return render_to_response("search_result.html", {'files': files, 'workNo': cd['workNo']})
                        
    else:
        form = SearchForm()
    return render_to_response('search_form.html', {'form': form})    

# test forms
@csrf_protect
def contact(request):
    if request.method == 'POST':
        form = ContactForm(request.POST)
        if form.is_valid():
            cd = form.cleaned_data
            send_mail(
                cd['subject'],
                cd['message'],
                cd.get('email', 'noreply@example.com'),
                ['siteowner@example.com'],
            )
            return HttpResponseRedirect('/ybt/thanks')
    else:
        form = ContactForm(initial={'subject': "I love your site!"})
    return render_to_response('contact_form.html', {'form': form})

def file_download(request):
    # do something...

    def file_iterator(file_name, chunk_size=512):
        with open(file_name, "rb") as f:
            while True:
                c = f.read(chunk_size)
                if c:
                    yield c 
                else:
                    break

    urlPath = request.get_full_path()
    workNo = urlPath.split("/")[-2]
    fileName = urlPath.split("/")[-1]
    
    the_file_name = workspace + workNo + "/" + fileName
    print the_file_name
    
    response = StreamingHttpResponse(file_iterator(the_file_name))
    response['Content-Type'] = 'application/octet-stream'
    response['Content-Disposition'] = 'attachment;filename="%s"' % fileName

    return response