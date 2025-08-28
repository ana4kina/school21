
def add_ingot(purse):
    new_purse = {}
    new_purse.update(purse)
    new_purse['gold_ingots'] = new_purse.get('gold_ingots', 0) + 1
    return new_purse

def get_ingot(purse):
    new_purse = {}
    new_purse.update(purse)
    if new_purse.get('gold_ingots', 0):
        new_purse['gold_ingots'] = new_purse.get('gold_ingots', 0) - 1
        if not new_purse['gold_ingots']:
            new_purse.pop('gold_ingots')
    return new_purse

def empty(purse):
    empty_dict = {}
    return empty_dict


if __name__ == '__main__':
    purse = {'gold_ingots': 20}
    purse_test = {'gold_ingots': 21, 'other': 42}
    purse_one = {'gold_ingots': 1}
    print("\nadd ", add_ingot(purse))
    print("check ", purse)
    print("add ", add_ingot(purse))
    print("get ", get_ingot(purse))
    print("empty ", empty(purse))
    print("empty test ", empty(purse_test))
    print("subject test ", add_ingot(get_ingot(add_ingot(empty(purse)))))
    print("get one", get_ingot(purse_one))