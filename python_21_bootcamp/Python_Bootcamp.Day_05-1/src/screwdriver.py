import requests
import sys


if __name__ == '__main__':
    # Set the URL for the file upload endpoint
    url = 'http://127.0.0.1:8888/'

    command = sys.argv[1] if len(sys.argv) > 1 else None
    # Define the file path of the file to be uploaded
    if not command:
        quit()
    if command == 'upload':
        file_path = sys.argv[2] if len(sys.argv) > 2 else None
        # Create a dictionary to hold the file data
        files = {'file': open(file_path, 'rb')}

        # Send the HTTP POST request to upload the file
        response = requests.post(url, files=files)

        # Check the response status code
        if response.status_code == 200:
            print('File uploaded successfully.')
        else:
            print('Failed to upload the file. Status code:', response.status_code)
    elif command == "list":
        url = 'http://127.0.0.1:8888/list/'
        response = requests.get(url)
        print(response.content.decode('utf-8'))


