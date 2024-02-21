class BankersAlgorithm:
    def __init__(self, allocation, max_demand, available):
        self.allocation = allocation
        self.max_demand = max_demand
        self.available = available
        self.num_processes = len(allocation)
        self.num_resources = len(available)
        self.need = [[max_demand[i][j] - allocation[i][j] for j in range(self.num_resources)] for i in range(self.num_processes)]
        self.safe_sequence = []

    def is_safe_state(self):
        work = self.available[:]
        finish = [False] * self.num_processes
        while True:
            found = False
            for i in range(self.num_processes):
                if not finish[i] and all(need <= work[j] for j, need in enumerate(self.need[i])):
                    work = [work[j] + self.allocation[i][j] for j in range(self.num_resources)]
                    self.safe_sequence.append(i)
                    finish[i] = True
                    found = True
                    break
            if not found:
                if all(finish):
                    return True  
                else:
                    return False  

    def request_resources(self, process_id, request):
        if all(req <= need for req, need in zip(request, self.need[process_id])):
            if all(req <= available for req, available in zip(request, self.available)):
                new_allocation = [a + b for a, b in zip(self.allocation[process_id], request)]
                new_need = [n - r for n, r in zip(self.need[process_id], request)]
                if BankersAlgorithm(self.allocation, self.max_demand, self.available).is_safe_state():
                    self.allocation[process_id] = new_allocation
                    self.need[process_id] = new_need
                    self.available = [a - r for a, r in zip(self.available, request)]
                    return True  
        return False  



if __name__ == "__main__":
    allocation = [[1,1,1],[1,1,1],[1,1,1]]
    max_demand = [[2,2,2], [2, 2, 2], [2,2,2]]
    available = [0,0,0]
    
    banker = BankersAlgorithm(allocation, max_demand, available)
    if banker.is_safe_state():
        print("Initial state is safe.")
        print("Safe sequence:", banker.safe_sequence)
        process_id = 0
        request = [0, 1, 0]  
        if banker.request_resources(process_id, request):
            print(f"Request for process {process_id} granted.")
            print("New allocation:", banker.allocation)
            print("New need:", banker.need)
            print("New available:", banker.available)
        else:
            print(f"Request for process {process_id} denied.")
    else:
        print("Initial state is not safe.")


# bankers algo for a deadlock avoidance 
# class constructor __init__ initializes algorithm with 3 main parameters   
    # allocation - this shows current allocation of resources to for each proceses
    # max demand - represents max demand of resources for each process
    # available - it shows the available resources at that given point of time 
# It calculates the 'need' matrix, which represents remaining resources needed by each process to complete execution

# The safe state method check s whether the current state of the system is safe or not, bankers safety algo is used here 
    # it has a finish vector to track whether a process has completed execution 
    # it goes through each and every process and checks if its resources can be satisfied with the available resources or not
    # iff a process can complete its execution, it goes through  the allocation of resources of that process and marks it finished 
    # if process is not completed then and cannot be executed in the current state, the system is to be unsafe else it is said to be safe.
    
# request resource method requests for an additional resource from the process 
# takes 2 parameters, process id and request 
# initially it checks that the process from which an additional resource is asked has already maximum resources or not with the help of 'max_demand', basically checks it's availibility 
# if both conditions are satisfied, it allocates a resource, and checks if the state is safe or unsafe.
# if it is safe - request accepted (granted), if unsafe - request rejected (denied)


 
  

