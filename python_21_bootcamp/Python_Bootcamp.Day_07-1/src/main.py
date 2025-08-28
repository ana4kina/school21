import pandas as pd
import sqlite3
from tabulate import tabulate
import random
from time import sleep
from tests.tests import db_tester, value_manager

name_db = 'quiz.db'

def read_db(name):
    with sqlite3.connect(name, detect_types=0) as con:
        query = "SELECT * FROM quiz"
        df = pd.read_sql_query(query, con, index_col='id')
        return df
    
def take_input():
    print('Give 4 numbers that are:', "- Respiration (measured in BPM, normally around 12-16 breaths per minute)",
    "- Heart rate (normally around 60 to 100 beats per minute)",
    "- Blushing level (categorical, 6 possible levels)",
    "- Pupillary dilation (current pupil size, 2 to 8 mm)", sep='\n')
    q1, q2, q3, q4 = value_manager()
    sm = sum(map(lambda x, y: int(x) * int(y), (q1, q2, q3, q4), [12 <= int(q1) <= 16, 60 <= int(q2) <= 100, 0 < int(q3) <= 6, 2 <= int(q4) <= 8]))
    return sm

    
def main_cycle(df, n):
    lst_answers = []
    lst = []
    for _ in range(n):
        random_row = df.sample(n=1)
        question =  random_row[['question', 'response_a', 'response_b', 'response_c', 'response_d']]
        question_table = tabulate(question.reset_index(drop=True), headers='keys', tablefmt='fancy_grid')
        print(question_table)
        sleep(1)
        print()
        answer = 'response_' + random.choice(('a', 'b', 'c', 'd'))
        print('your chose', answer)
        print()
        score = random_row[['correct_response']].values == random_row[[answer]].values
        score = score[0][0]
        lst_answers.append(score)
        lst.append(take_input())
    return sum(map(lambda x, y: int(x) * y, lst_answers, lst))
    
def make_decision(sm):
    if sm > 100:
        print('You are a human')
    else:
        print('you are not a human')


if __name__ == "__main__":
    df = read_db(name_db)
    db_tester(df)
    sm = main_cycle(df, 10)
    make_decision(sm)
    