from django.urls import path
from . import views

urlpatterns = [
    path('', views.home, name = 'FormApp'),
    path('form', views.signin, name = 'signin')
]