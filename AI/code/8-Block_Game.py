import numpy as np
import random
from heapq import heappop, heappush
from itertools import count

# Representation of the Domain
class EightPuzzle:
    def __init__(self, start_state, goal_state):
        self.start_state = np.array(start_state)
        self.goal_state = np.array(goal_state)
    
    def find_blank(self, state):
        """Find the position of the blank tile (represented as 0)."""
        i, j = np.where(state == 0)
        return i[0], j[0]

    # Move Generation Functions
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
    
    def swap(self, state, i1, j1, i2, j2):
        """Swap two elements in the state."""
        new_state = np.copy(state)
        new_state[i1, j1], new_state[i2, j2] = new_state[i2, j2], new_state[i1, j1]
        return new_state
    
    # Heuristic Functions
    def h1(self, state):
        """Count the number of misplaced tiles."""
        return np.sum(state != self.goal_state) - 1  # subtracting the blank tile
    
    def h2(self, state):
        """Compute the Manhattan distance for all tiles."""
        total_dist = 0
        for num in range(1, 9):
            i1, j1 = np.where(state == num)
            i2, j2 = np.where(self.goal_state == num)
            total_dist += abs(i1 - i2) + abs(j1 - j2)
        return total_dist
    
    # Best First Search Algorithm
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
        
        return -1  # return -1 if no solution

# Example Usage
start = [[1, 2, 3], [4, 0, 6], [7, 5, 8]]
goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
puzzle = EightPuzzle(start, goal)

# Run searches with both heuristics
print("Solution depth with h1:", puzzle.best_first_search('h1'))
print("Solution depth with h2:", puzzle.best_first_search('h2'))
