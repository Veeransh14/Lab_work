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
                    return True  # Safe state found
                else:
                    return False  # No safe state exists

    def request_resources(self, process_id, request):
        if all(req <= need for req, need in zip(request, self.need[process_id])):
            if all(req <= available for req, available in zip(request, self.available)):
                new_allocation = [a + b for a, b in zip(self.allocation[process_id], request)]
                new_need = [n - r for n, r in zip(self.need[process_id], request)]
                if BankersAlgorithm(self.allocation, self.max_demand, self.available).is_safe_state():
                    self.allocation[process_id] = new_allocation
                    self.need[process_id] = new_need
                    self.available = [a - r for a, r in zip(self.available, request)]
                    return True  # Request granted
        return False  # Request denied


# Example usage:
if __name__ == "__main__":
    allocation = [[0, 1, 0], [2, 0, 0], [3, 0, 2], [2, 1, 1], [0, 0, 2]]
    max_demand = [[7, 5, 3], [3, 2, 2], [9, 0, 2], [2, 2, 2], [4, 3, 3]]
    available = [3, 3, 2]
    
    banker = BankersAlgorithm(allocation, max_demand, available)
    if banker.is_safe_state():
        print("Initial state is safe.")
        print("Safe sequence:", banker.safe_sequence)
        process_id = 0
        request = [0, 1, 0]  # Request resources for process 0
        if banker.request_resources(process_id, request):
            print(f"Request for process {process_id} granted.")
            print("New allocation:", banker.allocation)
            print("New need:", banker.need)
            print("New available:", banker.available)
        else:
            print(f"Request for process {process_id} denied.")
    else:
        print("Initial state is not safe.")
