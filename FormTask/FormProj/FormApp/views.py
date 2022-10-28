from django.shortcuts import render
from django.http import HttpResponse
from .models import details
from django.views.decorators.csrf import csrf_exempt

# Create your views here.

def home(request):
    return render(request, 'home.html')

@csrf_exempt
def signin(request):
    name = request.POST['name']
    age = int(request.POST['age'])
    emailID = request.POST['emailID']
    phone = int(request.POST['phone'])
    
    user = details(name=name, age=age, emailID=emailID, phone=phone)
    user.save()
    return render(request, 'home.html')