# Shared memory and IPC using python
import multiprocessing
import time  

def writer(shared_list):
    """Function to write data to the shared list."""
    for i in range(5):
        shared_list.append(i)
        print(f"Writer added: {i}")
        time.sleep(1)  

def reader(shared_list):
    """Function to read data from the shared list."""
    old_len = 0
    while old_len < 5:
        if len(shared_list) > old_len:
            print(f"Reader read: {shared_list[old_len]}")
            old_len += 1
        time.sleep(0.5)  

if __name__ == '__main__':
    manager = multiprocessing.Manager()
    shared_list = manager.list()  
    
    
    writer_process = multiprocessing.Process(target=writer, args=(shared_list,))
    reader_process = multiprocessing.Process(target=reader, args=(shared_list,))
    
    writer_process.start()
    reader_process.start()
    
    writer_process.join()
    reader_process.join()



    # Manager and Shared List: We initiate a Manager() that allows creating a shared list. This list can be accessed and modified by different processes.
    # Writer and Reader Functions: The writer function adds integers to the shared list, and the reader function reads these integers. To simulate asynchronous behavior, there are delays (sleep) added.
    # Processes: Two separate processes are created for writing and reading. They operate on the same shared_list object managed by the Manager.