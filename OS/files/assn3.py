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

# Example usage:
import time

def worker(semaphore, id):
    print(f"Thread {id} trying to acquire semaphore")
    semaphore.acquire()
    print(f"Thread {id} acquired semaphore")
    time.sleep(2)  # Simulate some work being done
    semaphore.release()
    print(f"Thread {id} released semaphore")

semaphore = Semaphore()  # Initialize semaphore
threads = []

for i in range(5):
    t = threading.Thread(target=worker, args=(semaphore, i))
    threads.append(t)
    t.start()

for t in threads:
    t.join()
