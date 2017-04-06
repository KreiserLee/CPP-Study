# -*- coding: utf-8 -*-
# 表单框架最主要的用法是，为每一个将要处理的HTML的`` <Form>`` 定义一个Form类。 
# Django的forms框架处理HTML显示、数据校验、数据清理和表单错误重现。

from django import forms

# 以下为test Form类
class ContactForm(forms.Form):
    """
    它做的第一件事是将自己显示成HTML：
        cf = ContactForm()
        print cf 显示完整表单
        print cf.as_ul()
        print cf.as_p()
    Form对象做的第二件事是校验数据:
        cf = ContactForm({'subject': 'hello', 'email': 'liyang107@taikanglife.com', 'message': 'Nice site!'})
        1.一旦你对一个Form实体赋值，你就得到了一个绑定form:cf.is_bound
        2.调用任何绑定form的is_valid()方法，就可以知道它的数据是否合法:cf.is_valid()
        3.每一个邦定Form实体都有一个errors属性，它为你提供了一个字段与错误消息相映射的字典表:cf.errors(一个dict)
          查看每个字段的出错信息：cf['message'].errors
        4.如果一个Form实体的数据是合法的，它就会有一个可用的cleaned_data属性。 这是一个包含干净的提交数据的字典。
          Django的form框架不但校验数据，它还会把它们转换成相应的Python类型数据，这叫做清理数据。
    """
    subject = forms.CharField()
    email = forms.EmailField(required=False)
    # forms框架把每一个字段的显示逻辑分离到一组部件（widget）中。 
    # 每一个字段类型都拥有一个默认的部件，我们也可以容易地替换掉默认的部件，或者提供一个自定义的部件。
    message = forms.CharField(widget=forms.Textarea)
    #自定义字段的标签。 仅需使用label
    
class SearchForm(forms.Form):
    """
    银保通测试查询用表单
    """
    workNo = forms.CharField(label="任务号")
    dateTime = forms.DateField(required=False, label="日 期")
    



