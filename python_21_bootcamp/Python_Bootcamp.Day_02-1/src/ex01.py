from collections import Counter
import random

class Game(object):

    def __init__(self, matches=10):
        self.matches = matches
        self.registry = Counter()

    def play(self, player1, player2):
        # simulate number of matches
        # equal to self.matches
        for _ in range(self.matches):
            if player1.behavior == player2.behavior == 'cheat':
                self.registry.update({player1.name:0, player2.name:0})
            elif player1.behavior == player2.behavior == 'cooperate':
                self.registry.update({player1.name:2, player2.name:2})
            elif player1.behavior == 'cooperate' and player2.behavior == 'cheat':
                self.registry.update({player1.name:-1, player2.name:3})
            elif player1.behavior == 'cheat' and player2.behavior == 'cooperate':
                self.registry.update({player1.name:3, player2.name:-1})
            tmp = player1.behavior
            player1.next_behavior(player2.behavior)
            player2.next_behavior(tmp)


    def top3(self):
        lst = self.registry.most_common(3)
        for el in lst:
            print(*el)

class Player(object):
    def __init__(self, name='player'):
        self.behaviors = []
        self.name = name
        self.behavior = None

    def next_behavior(self):
        pass

class Chaeter(Player):
    def __init__(self, name='cheater'):
        self.behaviors = ['cheat']
        self.name = name
        self.behavior = self.behaviors[0]

    def next_behavior(self, enemy_b):
        pass

class Cooperator(Player):
    def __init__(self, name='cooperator'):
        self.behaviors = ['cooperate']
        self.name = name
        self.behavior = self.behaviors[0]

    def next_behavior(self, enemy_b):
        pass

class Copycat(Player):
    def __init__(self, name='copycat'):
        self.behaviors = ['cooperate', 'cheat']
        self.name = name
        self.behavior = self.behaviors[0]

    def next_behavior(self, enemy_b):
        self.behavior = enemy_b

class Grudger(Player):
    def __init__(self, name='grudger'):
        self.behaviors = ['cooperate', 'cheat']
        self.name = name
        self.behavior = self.behaviors[0]

    def next_behavior(self, enemy_b):
        self.behavior = enemy_b if enemy_b == 'cheat' else self.behavior

class Detective(Player):
    def __init__(self, name='detective'):
        self.behaviors = ["cooperate", "cheat", "cooperate", "cooperate"]
        self.name = name
        self.index = 0
        self.checker = False
        self.behavior = self.behaviors[self.index]

    def next_behavior(self, enemy_b):
        if enemy_b == 'cheat' and self.index < 4:
            self.checker = True
        self.index += 1
        if self.index < 4:
            self.behavior = self.behaviors[self.index]
        else:
            self.behavior = enemy_b if self.checker else 'cheat'

class Switcher(Player):
    def __init__(self, name='switcher'):
        self.behaviors = ['cooperate', 'cheat']
        self.name = name
        self.behavior = self.behaviors[0]

    def next_behavior(self, enemy_b):
        self.behavior = self.behaviors[0] if self.behavior == self.behaviors[1] else self.behaviors[1]

if __name__ == "__main__":
    game = Game(matches=10)
    print('Cheater vs Cooperator')
    game.play(Chaeter(), Cooperator())
    game.top3()
    game = Game(matches=10)
    print('Cheater vs Copycat')
    game.play(Chaeter(), Copycat())
    game.top3()
    game = Game(matches=10)
    print('Cheater vs Grudger')
    game.play(Chaeter(), Grudger())
    game.top3()
    game = Game(matches=10)
    print('Cheater vs Detective')
    game.play(Chaeter(), Detective())
    game.top3()
    game = Game(matches=10)
    print('Cooperator vs Copycat')
    game.play(Cooperator(), Copycat())
    game.top3()
    game = Game(matches=10)
    print('Cooperator vs Grudger')
    game.play(Cooperator(), Grudger())
    game.top3()
    game = Game(matches=10)
    print('Cooperator vs Detective')
    game.play(Cooperator(), Detective())
    game.top3()
    game = Game(matches=10)
    print('Copycat vs Grudger')
    game.play(Copycat(), Grudger())
    game.top3()
    game = Game(matches=10)
    print('Copycat vs Detective')
    game.play(Copycat(), Detective())
    game.top3()
    game = Game(matches=10)
    print('Grudger vs Detective')
    game.play(Grudger(), Detective())
    game.top3()
    print('Grudger vs Detective')
    game.play(Switcher(), Chaeter())
    game.top3()
    print('Grudger vs Detective')
    game.play(Switcher(), Cooperator())
    game.top3()
    print('Grudger vs Detective')
    game.play(Switcher(), Copycat())
    game.top3()
    print('Grudger vs Detective')
    game.play(Switcher(), Grudger())
    game.top3()
    print('Grudger vs Detective')
    game.play(Switcher(), Detective())
    game.top3()
    print('-----------------Each time new instance of player matches = 10-------------')
    game = Game(matches=10)
    game.play(Chaeter(), Cooperator())
    game.play(Chaeter(), Copycat())
    game.play(Chaeter(), Grudger())
    game.play(Chaeter(), Detective())
    game.play(Cooperator(), Copycat())
    game.play(Cooperator(), Grudger())
    game.play(Cooperator(), Detective())
    game.play(Copycat(), Grudger())
    game.play(Copycat(), Detective())
    game.play(Grudger(), Detective())
    game.play(Switcher(), Cooperator())
    game.play(Switcher(), Copycat())
    game.play(Switcher(), Grudger())
    game.play(Switcher(), Detective())
    game.top3()
    print('-----------------Each time new instance of player matches = 100-------------')
    game = Game(matches=100)
    game.play(Chaeter(), Cooperator())
    game.play(Chaeter(), Copycat())
    game.play(Chaeter(), Grudger())
    game.play(Chaeter(), Detective())
    game.play(Cooperator(), Copycat())
    game.play(Cooperator(), Grudger())
    game.play(Cooperator(), Detective())
    game.play(Copycat(), Grudger())
    game.play(Copycat(), Detective())
    game.play(Grudger(), Detective())
    game.play(Switcher(), Cooperator())
    game.play(Switcher(), Copycat())
    game.play(Switcher(), Grudger())
    game.play(Switcher(), Detective())
    game.top3()
    print('------------------The same players------------')
    players = [Chaeter(), Cooperator(), Copycat(), Grudger(), Detective(), Switcher()]
    game = Game(matches=random.randint(5,100))
    for _ in range(1000):
        game.play(random.choice(players), random.choice(players))
    game.top3()
    print('------------------The same players------------')
    players = [Chaeter(), Cooperator(), Copycat(), Grudger(), Detective(), Switcher()]
    game = Game(matches=random.randint(5,100))
    for _ in range(random.randint(50, 10000)):
        game.play(random.choice(players), random.choice(players))
    game.top3()
    print('------------------The same players------------')
    players = [Chaeter(), Cooperator(), Copycat(), Grudger(), Detective(), Switcher()]
    game = Game(matches=random.randint(5,100))
    for _ in range(random.randint(50, 10000)):
        game.play(random.choice(players), random.choice(players))
    game.top3()
    print('------------------The same players------------')
    players = [Chaeter(), Cooperator(), Copycat(), Grudger(), Detective(), Switcher()]
    game = Game(matches=random.randint(5,100))
    for _ in range(random.randint(50, 10000)):
        game.play(random.choice(players), random.choice(players))
    game.top3()
    print('------------------The same players------------')
    players = [Chaeter(), Cooperator(), Copycat(), Grudger(), Detective(), Switcher()]
    game = Game(matches=random.randint(5,100))
    for _ in range(random.randint(50, 10000)):
        game.play(random.choice(players), random.choice(players))
    game.top3()

    