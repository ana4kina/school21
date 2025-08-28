import argparse
import json
import redis
import logging

logging.basicConfig(level=logging.INFO, format='%(message)s')

def swap(message, bad_guys):
    data = message['metadata']
    sender = data['from']
    to_account = data['to']

    if sender in bad_guys and message['amount'] >= 0:
        data['from'], data['to'] = to_account, sender
        logging.info('--->Swapped<---')
    return message

def main():
    parser = argparse.ArgumentParser(description='manager of redis queue')
    parser.add_argument('-e', '--bad-guys', required=True, help='List 10-lenght elements neaded')
    args = parser.parse_args()
    bad_guys = args.bad_guys.split(',')
    redis_client = redis.Redis()
    pubsub = redis_client.pubsub()
    pubsub.subscribe('queue')

    for message in pubsub.listen():
        if message['type'] == 'message':
            data = message['data']
            parsed_message = json.loads(data)
            swapped_message = swap(parsed_message, bad_guys)
            logging.info(swapped_message)

if __name__ == '__main__':
    main()