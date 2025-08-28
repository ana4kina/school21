from collections import Counter

def split_booty(*args):
    booty = Counter()
    for purse in args:
        booty.update(purse)
    total = booty.get('gold_ingots', 0)
    return sorted([{'gold_ingots': total // 3 + ((total + 1) % 3) // 2},
            {'gold_ingots': total // 3 + (total % 3) // 2},
            {'gold_ingots': total // 3}], key=lambda x: x['gold_ingots'], reverse=True)
            

if __name__ == '__main__':
    purse1 = {'gold_ingots': 1}
    purse2 = {'gold_ingots': 3}
    purse3 = {'gold_ingots': 5, 'other': 21}
    purse4 = {'gold_ingots': 21}

    print(split_booty(purse1, purse2, purse3, {'test': 99}))
    print('one', split_booty({'gold_ingots': 1}))
    print('one', split_booty({'gold_ingots': 16}))
    print('zero', split_booty({'gold_ingots': 0}))
    print('empty', split_booty())
    print(split_booty({'gold_ingots': 3}, {'gold_ingots': 2}, {'gold_ingots': 12}))