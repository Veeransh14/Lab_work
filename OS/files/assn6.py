class BankerAlgorithm:
    def __init__(self, allocation, max_claim, available):
        self.allocation = allocation
        self.max_claim = max_claim
        self.available = available
        self.num_processes = len(allocation)
        self.num_resources = len(available)

    def is_safe_state(self, finish, work, need):
        finished_processes = [False] * self.num_processes
        while True:
            found = False
            for i in range(self.num_processes):
                if not finished_processes[i] and all(need[i][j] <= work[j] for j in range(self.num_resources)):
                    for j in range(self.num_resources):
                        work[j] += self.allocation[i][j]
                    finished_processes[i] = True
                    found = True
            if not found:
                break
        return all(finished_processes)

    def detect_deadlock(self):
        work = list(self.available)
        need = [[self.max_claim[i][j] - self.allocation[i][j] for j in range(self.num_resources)] for i in range(self.num_processes)]
        finish = [False] * self.num_processes
        if self.is_safe_state(finish, work, need):
            return False
        return True


allocation1 = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]
max_claim1 = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]
available1 = [3, 3, 2]

allocation2 = [[1,1,1],[1,1,1],[1,1,1]]
max_claim2 = [[2,2,2,],[2,2,2],[2,2,2]]
available2 = [0,0,0]

banker1 = BankerAlgorithm(allocation1, max_claim1, available1)
if banker1.detect_deadlock():
    print("Deadlock detected in Example 1.")
else:
    print("No deadlock detected in Example 1.")

banker2 = BankerAlgorithm(allocation2, max_claim2, available2)
if banker2.detect_deadlock():
    print("Deadlock detected in Example 2.")
else:
    print("No deadlock detected in Example 2.")




# bamker algo class is created
# has a constructor __init__ and it has 3 attributes:
    # allocaction, max_claim, available
    # it has attributes which also calculates number of process and number of resources

# a safte state method is defined, which check if the system state is safe or not, it does this by simulating allocation of resources and verifying if all processes are able to finish or not 
# detect deadlock uses safe state to check id there is a deadlock in the system or not. If system unsafe - deadlock present 

# INput data should have - allocation, max_claim and availabile
    