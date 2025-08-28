import grpc
import spaceship_pb2
import spaceship_pb2_grpc
import argparse
from google.protobuf.json_format import MessageToJson

def run(kwards):

    channel = grpc.insecure_channel('localhost:50051')
    stub = spaceship_pb2_grpc.ReportStub(channel)
        
    request = spaceship_pb2.Coordinates(**kwards)

    response_stream = stub.GetReport(request)
    for response in response_stream:
        print(MessageToJson(response, indent=4,
                                    preserving_proto_field_name=True,
                                    including_default_value_fields=True))

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
