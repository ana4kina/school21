from django.shortcuts import render, redirect
from .models import UploadedFile
from django.http import HttpResponse

def upload_file(request):
    uploaded_files = UploadedFile.objects.all()
    
    if request.method == 'POST':
        uploaded_file = request.FILES.get('file')
        if uploaded_file:
            allowed_extensions = ['mp3', 'ogg', 'wav']
            file_extension = uploaded_file.name.split('.')[-1].lower()
            if file_extension in allowed_extensions:
                UploadedFile.objects.create(file=uploaded_file)
                return render(request, 'music/success.html', {'uploaded_files': uploaded_files})
            else:
                return render(request, 'music/error.html', {'uploaded_files': uploaded_files})
    
    return render(request, 'music/upload.html', {'uploaded_files': uploaded_files})

def list(request):
    uploaded_files = UploadedFile.objects.all()
    return HttpResponse('\n'.join([uploaded_file.file.name for uploaded_file in uploaded_files]))