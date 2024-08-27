import numpy as np  # majorly handles and functions the 2D array
import random  # gives random iterated numbers as per the requirement of the experiment
from heapq import heappop, heappush  # provides an implementation of a priority queue, which is used in BFS algo to expand the node with the lowest heuristic value
from itertools import count
from collections import deque  # used for BFS and DFS implementations
import matplotlib.pyplot as plt  # used for graphical representation


class EightPuzzle:
    def __init__(self, start_state, goal_state):
        self.start_state = np.array(start_state)
        self.goal_state = np.array(goal_state)
    
    # this function initializes the puzzle with a start state and also marks the goal state - stored as 2d arrays 
    
    def find_blank(self, state):
        """Find the position of the blank tile (represented as 0)."""
        i, j = np.where(state == 0)
        return i[0], j[0]
    # this function helps to find the blank tile in the puzzle and return that spot so that the puzzle can be solved 
    

    def generate_moves(self, state):
        """Generate possible moves given the position of the blank tile."""
        i, j = self.find_blank(state)
        moves = []
        if i > 0:
            moves.append(('up', self.swap(state, i, j, i-1, j)))
        if i < 2:
            moves.append(('down', self.swap(state, i, j, i+1, j)))
        if j > 0:
            moves.append(('left', self.swap(state, i, j, i, j-1)))
        if j < 2:
            moves.append(('right', self.swap(state, i, j, i, j+1)))
        return moves
    
    # this func generates all possible moves, moving a tile in any direction possible (up, down, left and right), after each valid move it returns a list of new possible moves 
    
    def swap(self, state, i1, j1, i2, j2):
        """Swap two elements in the state."""
        new_state = np.copy(state)
        new_state[i1, j1], new_state[i2, j2] = new_state[i2, j2], new_state[i1, j1]
        return new_state
    # this func would swap a blank tile with the adjacent tile in the puzzle and will return the new state of the puzzle after the swapping procedure 
    
    
    ## Heuristic Functions
    def h1(self, state):
        """Count the number of misplaced tiles."""
        return np.sum(state != self.goal_state) - 1 
    
    # this counts number of misplaced tiles in current state comparing it with the goal state
    
    def h2(self, state):
        """Compute the Manhattan distance for all tiles."""
        total_dist = 0
        for num in range(1, 9):
            i1, j1 = np.where(state == num)
            i2, j2 = np.where(self.goal_state == num)
            total_dist += abs(i1 - i2) + abs(j1 - j2)
        return total_dist
    
    # this calculates the manhattan distance (as mentioned in the procedure) for each tile from its current position to its goal position 
    # manhattan distance is basically a sum of horizontal and vertical distances 
    
    ## Best First Search Algorithm
    def best_first_search(self, heuristic='h1'):
        """Best First Search using specified heuristic function."""
        open_list = []
        closed_set = set()
        initial = (getattr(self, heuristic)(self.start_state), self.start_state.tobytes(), self.start_state, 0)
        heappush(open_list, initial)
        unique = count()
        
        while open_list:
            _, _, current, depth = heappop(open_list)
            if np.array_equal(current, self.goal_state):
                return depth
            
            current_bytes = current.tobytes()
            if current_bytes in closed_set:
                continue
            closed_set.add(current_bytes)
            
            for move, new_state in self.generate_moves(current):
                if new_state.tobytes() not in closed_set:
                    heappush(open_list, (getattr(self, heuristic)(new_state), next(unique), new_state, depth + 1))
        
        return -1  # if no solution
    # a priority queue, that stores nodes to be expanded, these are prioritised by heuristic func, give closed state which provides set of visited state to avoid revisiting
    # this search return depth of the solution (number of moves more(remaining))  

    ## Breadth First Search Algorithm
    def breadth_first_search(self):
        """Breadth First Search for 8-puzzle."""
        open_list = deque([(self.start_state, 0)])
        closed_set = set()
        
        while open_list:
            current, depth = open_list.popleft()
            if np.array_equal(current, self.goal_state):
                return depth
            
            current_bytes = current.tobytes()
            if current_bytes in closed_set:
                continue
            closed_set.add(current_bytes)
            
            for move, new_state in self.generate_moves(current):
                if new_state.tobytes() not in closed_set:
                    open_list.append((new_state, depth + 1))
        
        return -1  # if no solution
    
    ## Depth First Search Algorithm
    def depth_first_search(self):
        """Depth First Search for 8-puzzle."""
        open_list = deque([(self.start_state, 0)])
        closed_set = set()
        
        while open_list:
            current, depth = open_list.pop()
            if np.array_equal(current, self.goal_state):
                return depth
            
            current_bytes = current.tobytes()
            if current_bytes in closed_set:
                continue
            closed_set.add(current_bytes)
            
            for move, new_state in self.generate_moves(current):
                if new_state.tobytes() not in closed_set:
                    open_list.append((new_state, depth + 1))
        
        return -1  # if no solution


def generate_random_start(goal_state):
    """Generate a random start state by shuffling the goal state."""
    flat_goal = goal_state.flatten()
    np.random.shuffle(flat_goal)
    return flat_goal.reshape((3, 3))

# gives a random 2d array for the start state

goal = np.array([[1, 2, 3], [8, 0, 4], [7, 6, 5]])
start = generate_random_start(goal)

puzzle = EightPuzzle(start, goal)

print("Start State:")
print(puzzle.start_state)
print("\nGoal State:")
print(puzzle.goal_state)

# Run searches with all algorithms
depth_h1 = puzzle.best_first_search('h1')
depth_h2 = puzzle.best_first_search('h2')
depth_bfs = puzzle.breadth_first_search()
depth_dfs = puzzle.depth_first_search()

# Print the results
print("\nSolution depth with h1 (Best First Search):", depth_h1)
print("Solution depth with h2 (Best First Search):", depth_h2)
print("Solution depth with Breadth-First Search:", depth_bfs)
print("Solution depth with Depth-First Search:", depth_dfs)

# Graphical representation
algorithms = ['Best First Search (h1)', 'Best First Search (h2)', 'Breadth-First Search', 'Depth-First Search']
depths = [depth_h1, depth_h2, depth_bfs, depth_dfs]

plt.figure(figsize=(10, 6))
plt.bar(algorithms, depths, color=['blue', 'green', 'orange', 'red'])
plt.title('Comparison of Search Algorithms in 8-Puzzle Problem')
plt.xlabel('Search Algorithms')
plt.ylabel('Solution Depth (Number of Moves)')
plt.show()
