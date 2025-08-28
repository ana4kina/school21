from ingots import *

def squeak(func):
    def wrapper(*args, **kwargs):
        print('SQUEAK', func.__name__)
        res = func(*args)
        return res
    return wrapper


if __name__ == '__main__':

    purse = {'gold_ingots': 21}

    decorated_add = squeak(add_ingot)
    decorated_get = squeak(get_ingot)
    decorated_empty = squeak(empty)
    decorated_add(purse)
    decorated_get(purse)
    decorated_empty(purse)