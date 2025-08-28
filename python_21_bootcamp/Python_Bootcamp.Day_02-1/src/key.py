
class Key(object):
    def __len__(self):
        return 1337
    
    def __getitem__(self, num):
        return self

    def __gt__(self, val):
        return val + 1 > val
    
    def __init__(self, passphrase=None):
        self.passphrase = "zax2rulez"

    def __str__(self):
        return 'GeneralTsoKeycard'
    
    def __eq__(self, __value: object) -> bool:
        return True
    

if __name__ == "__main__":
    key = Key()

    print(len(key))
    print(key[404] == 3)
    print(key > 9000)
    print(key.passphrase)
    print(str(key))

    assert len(key) == 1337
    assert key[404] == 3
    assert key > 9000
    assert key.passphrase == "zax2rulez"
    assert str(key) == "GeneralTsoKeycard"
