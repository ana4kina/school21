from collections.abc import Callable, Iterable, Mapping
import threading
from typing import Any, List
from time import sleep

class Screwdriver(threading.Semaphore):
    
    def __init__(self, value: int = 1) -> None:
        super().__init__(value)

class Doctor(threading.Thread):

    def __init__(self,i , group: None = None, target: Callable[..., object] | None = None, name: str | None = None, args: Iterable[Any] = ..., kwargs: Mapping[str, Any] | None = None, *, daemon: bool | None = None) -> None:
        self.my_number = i
        target = self.routine
        super().__init__(group, target, name, args, kwargs, daemon=daemon)

    def routine(self, screwdriver_lst: List[Screwdriver]):
        while True:
            self.take_screwdrivers(screwdriver_lst)

    def take_screwdrivers(self, screwdriver_lst: List[Screwdriver]):
        sub = 0
        if self.my_number == 4:
            sub = 5
        screwdriver_lst[self.my_number].acquire()
        screwdriver_lst[self.my_number + 1 - sub].acquire()
        print(f'Doctor {self.my_number + 9}: BLAST!')
        screwdriver_lst[self.my_number].release()
        screwdriver_lst[self.my_number + 1 - sub].release()
        sleep(0.5)
        

if __name__ == '__main__':
    screwdrivers = [Screwdriver() for _ in range(5)]
    doctors = [Doctor(i, name=f'Doctor{i + 9}', args=(screwdrivers,)) for i in range(5)]
    for doctor in doctors:
        doctor.start()





