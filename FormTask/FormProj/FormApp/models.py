from django.db import models

# Create your models here.

class details(models.Model):
    name = models.CharField(max_length = 20)
    age = models.CharField(max_length = 20)
    emailID = models.EmailField()
    phone = models.CharField(max_length = 20)
    class Meta:
        db_table='Details'