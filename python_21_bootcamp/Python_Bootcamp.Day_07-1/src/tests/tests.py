


def input_tester(q1, q2, q3, q4):
    assert 12 <= int(q1) <= 16, 'Respiration around 12-16 breaths'
    assert 60 <= int(q2) <= 100, 'Heart rate around 60 to 100 beats per minute'
    assert 0 < int(q3) <= 6, 'Blushing level 1 - 6 possible levels'
    assert 2 <= int(q4) <= 8, 'Pupillary dilation 2 to 8 mm'

def db_tester(df):
    assert len(df) >= 10, 'Too little questions'
    assert len(df.columns) > 4, "Not enough columns"
    assert not df.isna().any().any(), 'empty cells'

def value_manager():
    inp = input()
    try:
        assert len(inp.split()) == 4, 'not enough numbers'
        q1, q2, q3, q4 = (eval(x) for x in inp.split())
        input_tester(q1, q2, q3, q4)
    except Exception as e:
        print('wrong input')
        q1, q2, q3, q4 = value_manager()
    return (q1, q2, q3, q4)
    

