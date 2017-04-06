from django.conf.urls import patterns, include, url
from django.contrib import admin

import ybt.views

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'Tktestsite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),
    # http://host/ybt/ url
    url(r'^$', ybt.views.ybt),
    url(r'^search/$', ybt.views.search),
    
    # test form
    url(r'^contact/$', ybt.views.contact),
    
    url('^fileDownload/$', ybt.views.file_download),#download
    url('^result/', ybt.views.file_download)
)
