import random
import time

# def dynamic_method():
#     emit_gel.sign *= -1

# def emit_gel(step):
#     setattr(emit_gel, 'sign', 1)
#     setattr(emit_gel, 'send', dynamic_method)
#     step = random.randint(0, step)
#     i = 50
#     while True:
#         yield i
#         i += step * emit_gel.sign

# def valve(step):
#     for i in emit_gel(step):
#         print(i)
#         if i > 90 or i < 10:
#             print(f'Pressure {i}')
#             quit(1)
#         if i > 80 or i < 20:
#             emit_gel.send()
#         time.sleep(0.5)
#-------------------------------------------------------------------
# def emit_gel(step):
#     i = 50
#     sign = 1
#     while True:
#         sign = yield i
#         i += sign * random.randint(0, step)

# def valve(step):
#     sign = 1
#     gen = emit_gel(step)
#     i = next(gen)
#     while 0 <= i <= 100:
#         print(i)
#         if i > 90 or i < 10:
#             print(f'Pressure {i}')
#             gen.close()
#             break
#         elif i > 80 or i < 20:
#             sign *= -1
#         i = gen.send(sign)
#         time.sleep(0.1)
#-------------------------------------------------------------------
        
def emit_gel(step):
    i = 50
    sign = 1
    while True:
        sign *= yield i
        i += sign * random.randint(0, step)

def valve(step):
    sign = 1
    gen = emit_gel(step)
    i = next(gen)
    while 0 <= i <= 100:
        print(i)
        if i > 90 or i < 10:
            print(f'Pressure {i}')
            gen.close()
            break
        elif i > 80 or i < 20:
            sign = -1
        i = gen.send(sign)
        sign = 1
        time.sleep(0.1)

if __name__ == "__main__":
    valve(1)
