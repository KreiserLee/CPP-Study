from django.conf.urls import patterns, include, url
from django.contrib import admin

import ybt.urls

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'Tktestsite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^ybt/', include(ybt.urls)),
    
)
