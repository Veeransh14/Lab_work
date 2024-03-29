import threading
import time
import random

BUFFER_SIZE = 2
mutex = threading.Semaphore(1)
empty = threading.Semaphore(BUFFER_SIZE)
full = threading.Semaphore(0)
buffer = []

def producer():
    while True:
        item = random.randint(1, 100)
        empty.acquire()
        mutex.acquire()
        buffer.append(item)
        print(f"Produced item {item}. Buffer: {buffer}")
        mutex.release()
        full.release()
        time.sleep(random.uniform(0.1, 0.5))

def consumer():
    while True:
        full.acquire()
        mutex.acquire()
        item = buffer.pop(0)
        print(f"Consumed item {item}. Buffer: {buffer}")
        mutex.release()
        empty.release()
        time.sleep(random.uniform(0.1, 0.5))

producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)

producer_thread.start()
consumer_thread.start()

producer_thread.join()
consumer_thread.join()

# This program simulates between the producer-consumer problem using semaphores. 
# It creates 2 threads, each for the producer and for the consumer.
# the producer thread randomly and continuously generates random items and adds them to a shared buffer.
# the consumer thread continuously consumes items from the buffer. Semaphores are used to control access to the buffer.