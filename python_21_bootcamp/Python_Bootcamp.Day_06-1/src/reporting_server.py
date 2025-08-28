import grpc
from concurrent import futures
import spaceship_pb2
import spaceship_pb2_grpc
import random
from time import sleep

officers_names = ('John', 'Mary', 'David', 'Karen', 'Steven', 'Alan')
officers_surnames = ('Smith', 'Johnson', 'Williams', 'Jones', 'Brown', 'Black')
officers_ranks = ('Captain', 'Lieutenant', 'Sergeant', 'Commander')

enemies_spaceships = ('Death Star', 'Executor', 'Star Destroyer', 'Imperial Shuttle', 'Unknown')
ally_spaceships = ('Normandy', 'X-Wing', 'Millennium Falcon')


def get_officer():
    return {
        "first_name": random.choice(officers_names),
        "last_name": random.choice(officers_surnames),
        "rank": random.choice(officers_ranks)
    }

def generate_random_spaceship():

    ship = spaceship_pb2.Spaceship()
    officers_num = random.randint(0, 10)
    ship.alignment = random.randint(0, 1)
    ship.name = random.choice(ally_spaceships)
    ship.ship_class = random.randint(0, 5)
    ship.length = round(random.uniform(80.0, 20_000.0), 1)
    ship.crew_size = random.randint(4, 500)
    ship.armed = random.randint(0, 1)

    spaceship = {
        'alignment': ship.alignment,
        'name': ship.name,
        'ship_class': ship.ship_class,
        'length': ship.length,
        'crew_size': ship.crew_size,
        'armed': ship.armed,
        'officers': [get_officer() for _ in range(officers_num)]
    }
    return spaceship

class ReportService(spaceship_pb2_grpc.ReportServicer):
    def GetReport(self, request, context):
        for _ in range(random.randint(1, 10)):
            spaceship = spaceship_pb2.Spaceship(**generate_random_spaceship())
            print(generate_random_spaceship())
            sleep(0.1)
            yield spaceship

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    spaceship_pb2_grpc.add_ReportServicer_to_server(ReportService(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
