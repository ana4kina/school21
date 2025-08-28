from wsgiref.simple_server import make_server
from urllib.parse import parse_qs



vars ={"Cyberman": "John Lumic",
    "Dalek": "Davros",
    "Judoon": "Shadow Proclamation Convention 15 Enforcer",
    "Human": "Leonardo da Vinci",
    "Ood": "Klineman Halpen",
    "Silence": "Tasha Lem",
    "Slitheen": "Coca-Cola salesman",
    "Sontaran": "General Staal",
    "Time Lord": "Rassilon",
    "Weeping Angel": "The Division Representative",
    "Zygon": "Broton"}

def start_response(arg1, arg2):
    pass

def application (environ, start_response):
        # Build the response body possibly
    # using the supplied environ dictionary
    query_params = parse_qs(environ.get('QUERY_STRING', {}))
    if query_params and 'species' in query_params and len(query_params['species']) == 1 and query_params['species'][0] in vars:
        status = '200 OK'
        response_body = f'{{"credentials": "{query_params["species"][0]}}}\n"'
    else:
        status = '404 Not Found'
        response_body = '{"credentials": "Unknown"}\n'
    response_body = response_body.encode('utf-8')
    response_headers = [
        ('Content-Type', 'text/html'),
        ('Content-Length', str(len(response_body)))
    ]

    # Send them to the server using the supplied function
    start_response(status, response_headers)
    # Return the response body. Notice it is wrapped
    # in a list although it could be any iterable.
    return [response_body]

if __name__ == '__main__':
    httpd = make_server(
    'localhost', # The host name
    8888, # A port number where to wait for the request
    application # The application object name, in this case a function
    )

    # Wait for a single request, serve it and quit
    httpd.handle_request()