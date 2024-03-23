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
        # Release the lock after critical section
        lock.release()

# Create multiple threads that will access the shared resource
threads = []
for _ in range(5):
    t = threading.Thread(target=modify_shared_resource)
    threads.append(t)

# Start the threads
for t in threads:
    t.start()

# Wait for all threads to complete
for t in threads:
    t.join()

print("All threads completed.")
