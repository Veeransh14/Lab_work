import time
import threading
import random

class ThreadCounter:
    def __init__(self):
        self.counter = 0
        self.lock = threading.Lock()

    def count(self, thread_no):
        while self.counter < 20:
            self.lock.acquire()
            self.counter += 1
            print(f"{thread_no} Just increased counter to {self.counter}")
            time.sleep(1)
            print(f"{thread_no}: Done some work & now value is: {self.counter}")
            self.lock.release()
            time.sleep(random.randint(1,3))

tc = ThreadCounter()
for i in range(10):
    t = threading.Thread(target=tc.count, args=(i,))
    t.start()


# Thread counter class : represents a thread safe counter with attributes 'counter' and lock 
# count method : each thread increaments the counter until it reaches 20, ensuring thread safety by using locks, it the prints the thread number 
# threading : main loop creates 10 threads, each initialized with the count method
# Increament counter : threads acquire lock, increament counter, and release lock to ensure exclusive access 
# simulation : threads simulate work by sleeping for random intervals after each increament