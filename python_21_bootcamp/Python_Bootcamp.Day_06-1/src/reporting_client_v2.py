import grpc
import spaceship_pb2 as spaceship_pb2
import spaceship_pb2_grpc as spaceship_pb2_grpc
import argparse
from pydantic import BaseModel
from google.protobuf.json_format import MessageToJson
import json

class Validator(BaseModel):
    alignment: str
    name: str
    ship_class: str
    length: float
    crew_size: int
    armed: bool
    officers: list

    def main_check(cls):
        if all(cls.ship_class == 'CORVETTE', 
                80 <= cls.lenght <= 250 ,
                4 <= cls.crew_size <= 10,
                cls.armed, 
                cls.alignment == 'ENEMY'):
            return 
        if all(cls.ship_class == 'FRIGATE',
                300 <= cls.lenght <= 600,
                10 <= cls.crew_size <= 15,
                cls.armed,
                cls.alignment == 'ALLY'):
            return 
        if all(cls.ship_class == 'CRUISER',
                500 <= cls.lenght <= 1000,
                15 <= cls.crew_size <= 30,
                cls.armed,
                cls.alignment == 'ENEMY'):
            return
        if all(cls.ship_class == 'DESTROYER',
                800 <= cls.lenght <= 2000,
                50 <= cls.crew_size <= 80,
                cls.armed,
                cls.alignment == 'ALLY'):
            return
        if all(cls.ship_class == 'CARRIER',
                1000 <= cls.lenght <= 4000,
                120 <= cls.crew_size <= 250,
                not cls.armed,
                cls.alignment == 'ENEMY'):
            return
        if all(cls.ship_class == 'DREADNOUGHT',
                5000 <= cls.lenght <= 20000,
                300 <= cls.crew_size <= 500,
                cls.armed,
                cls.alignment == 'ENEMY'):
            return
        raise ValueError("Wrong data")

def run(kwards):

    channel = grpc.insecure_channel('localhost:50051')
    stub = spaceship_pb2_grpc.ReportStub(channel)
        
    request = spaceship_pb2.Coordinates(**kwards)

    response_stream = stub.GetReport(request)

    
    for response in response_stream:
        message_json = MessageToJson(response, indent=4,
                        preserving_proto_field_name=True,
                        including_default_value_fields=True)
        try:
            validator = Validator(**json.loads(message_json))
            validator.main_check()
        except:
            print('\033[91m', message_json, '\033[0m')
        else:
            print('\033[92m', message_json, '\033[92m')
            
        
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='grpc client')
    parser.add_argument("ascension_h", type=int, help="latitude_h")
    parser.add_argument("ascension_m", type=int, help="latitude_m")
    parser.add_argument("ascension_s", type=float, help="latitude_s")
    parser.add_argument("declination", type=int, help="longitude_h")
    parser.add_argument("declination_m", type=int, help="longitude_m")
    parser.add_argument("declination_s", type=float, help="longitude_s")
    args = parser.parse_args()
    run(dict(args._get_kwargs()))
