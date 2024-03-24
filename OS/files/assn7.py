import threading


shared_resource = 0


lock = threading.Lock()

def modify_shared_resource():
    global shared_resource

    lock.acquire()
    try:

        shared_resource += 1
        print(f"Shared resource value after modification: {shared_resource}")
    finally:
        
        lock.release()


threads = []
for _ in range(5):
    t = threading.Thread(target=modify_shared_resource)
    threads.append(t)


for t in threads:
    t.start()


for t in threads:
    t.join()

print("All threads completed.")




    # We define a shared resource (shared_resource) that multiple threads will access.
    # We create a lock using threading.Lock().
    # The modify_shared_resource() function represents a critical section where the shared resource is being modified. Before accessing the shared resource, the thread acquires the lock using lock.acquire(), ensuring exclusive access. After modifying the shared resource, the lock is released using lock.release().
    # Multiple threads are created to concurrently execute modify_shared_resource().
    # Each thread executes the critical section atomically, ensuring that only one thread can access the shared resource at a time.
    # The join() method is called on each thread to wait for all threads to complete before printing "All threads completed."