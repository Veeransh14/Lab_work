import random

def generate_k_sat_problem(k, m, n):
    variables = range(1, n+1)
    problem = []
    for _ in range(m):
        clause = random.sample(variables, k)
        clause = [(-x if random.random() < 0.5 else x) for x in clause]
        problem.append(clause)
    return problem

def main():
    k = int(input("Enter the number of literals per clause (k): "))
    m = int(input("Enter the number of clauses (m): "))
    n = int(input("Enter the number of variables (n): "))
    k_sat_problem = generate_k_sat_problem(k, m, n)
    print("\nGenerated k-SAT Problem:")
    for clause in k_sat_problem:
        print(clause)

if __name__ == "__main__":
    main()
