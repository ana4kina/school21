import json
import random
import redis
import logging
import time

logging.basicConfig(level=logging.INFO)

def generate_message():
    message = {
        'metadata': {'from': str(random.randint(1000000000, 9999999999)),
                    'to': str(random.randint(1000000000, 9999999999))},
        'amount': random.randint(-10000, 10000)
    }
    return json.dumps(message)

def main():
    redis_client = redis.Redis()

    while True:
        time.sleep(0.5)
        message = generate_message()
        logging.info(message)
        redis_client.publish('queue', message)

if __name__ == '__main__':
    main()