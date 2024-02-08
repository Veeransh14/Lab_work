import threading

class Semaphore:
    def __init__(self, initial=1):
        self.lock = threading.Lock()
        self.value = initial

    def acquire(self):
        with self.lock:
            while self.value == 0:
                self.lock.release()
                self.lock.acquire()
            self.value -= 1

    def release(self):
        with self.lock:
            self.value += 1


import time

def worker(semaphore, id):
    print(f"Thread {id} trying to acquire semaphore")
    semaphore.acquire()
    print(f"Thread {id} acquired semaphore")
    time.sleep(2) 
    semaphore.release()
    print(f"Thread {id} released semaphore")

semaphore = Semaphore()  
threads = []

for i in range(5):
    t = threading.Thread(target=worker, args=(semaphore, i))
    threads.append(t)
    t.start()

for t in threads:
    t.join()
    
    
    #     Semaphore Class:
    #     The Semaphore class is defined to mimic the functionality of semaphores in threading. It is initialized with an initial value (defaulting to 1 if not provided).
    #     It contains two methods: acquire() and release(), which are analogous to the operations of acquiring and releasing a semaphore.

    # __init__() Method:
    #     Initializes the semaphore with a given initial value (defaulting to 1).
    #     It also initializes a threading.Lock() object named lock, which will be used to ensure thread-safe access to the semaphore's internal state.

    # acquire() Method:
    #     Implements the semaphore's acquire operation.
    #     It first acquires the lock to ensure exclusive access to the semaphore's state.
    #     If the semaphore's value is 0 (indicating no available resource), it enters a busy-wait loop, repeatedly releasing and re-acquiring the lock until the semaphore's value becomes non-zero.
    #     Once a resource is available (i.e., semaphore's value becomes non-zero), it decrements the semaphore's value to indicate that a resource has been acquired.

    # release() Method:
    #     Implements the semaphore's release operation.
    #     It first acquires the lock to ensure exclusive access to the semaphore's state.
    #     It increments the semaphore's value to indicate that a resource has been released.

    # worker() Function:
    #     Represents a simple worker function that simulates some work being done.
    #     It acquires the semaphore, performs a simulated work for 2 seconds, and then releases the semaphore.

    # Example Usage:
    #     Initializes a Semaphore object.
    #     Creates and starts five threads, each running the worker() function with the initialized semaphore.
    #     Joins all threads to ensure they complete execution before the program terminates.
