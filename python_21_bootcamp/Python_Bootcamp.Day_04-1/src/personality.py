import random

def get_scores():
    lst = random.sample(range(101), 5)
    while sum(lst) != 100:
        lst = random.sample(range(101), 5)
    return lst


def turrets_generator():
    neuroticism, openness, conscientiousness, extraversion, agreeableness = get_scores()
    class_name = "Turret"
    base_classes = (object,)
    class_dict = {
        "shoot": lambda self: print("Shooting"),
        "search": lambda self: print("Searching"),
        "talk": lambda self: print("Talking"),
        "neuroticism":neuroticism,
        "openness":openness,
        "conscientiousness":conscientiousness,
        "extraversion":extraversion,
        "agreeableness":agreeableness,
        '__str__': lambda self: f'''\
                class: Turret
                personality traits: {self.neuroticism}, {self.openness}, {self.conscientiousness}, {self.extraversion}, {self.agreeableness}
                actions: shoot, search, talk'''
    }

    CustomClass = type(class_name, base_classes, class_dict)
    instance = CustomClass()
    return instance

if __name__ == "__main__":
    test_elem = turrets_generator()
    print(test_elem)
    test_elem.shoot()
    test_elem.search()
    test_elem.talk()
    print(test_elem.neuroticism)
    print(test_elem.openness)
    print(test_elem.conscientiousness)
    print(test_elem.extraversion)
    print(test_elem.agreeableness)