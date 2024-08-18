import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def display(room):
    for row in room:
        print(row)

n = int(input("Enter the number of rows: "))
m = int(input("Enter the number of columns: "))

room = [[1 for _ in range(m)] for _ in range(n)]
display(room)

for x in range(n):
    for y in range(m):
        room[x][y] = random.choice([0, 1])
display(room)

fig, ax = plt.subplots()
cax = ax.matshow(room, cmap="coolwarm")
total_cells = n * m
cleaned_cells = 0
total_cleanliness = 0.0
cleanliness_threshold = 0.01  # Define the threshold for considering a cell as clean

def update(frame):
    global cleaned_cells, total_cleanliness
    for x in range(n):
        for y in range(m):
            if room[x][y] == 1:
                cleanliness_level = random.uniform(0.01, 1.0)  # Random cleanliness level between 50% and 100%
                room[x][y] = cleanliness_level
                total_cleanliness += cleanliness_level
                if cleanliness_level >= cleanliness_threshold:
                    cleaned_cells += 1
                cax.set_data(room)
                ax.set_title(f"Cleaned: {cleaned_cells}/{total_cells} cells")
                plt.pause(0.1)
    return [cax]

ani = animation.FuncAnimation(fig, update, frames=n*m, blit=False, repeat=False)

plt.colorbar(cax)
plt.show()

performance = (cleaned_cells / total_cells) * 100
accuracy = (total_cleanliness / total_cells) * 100

print("Final room state:")
display(room)
print(f"Performance: {100 - performance:.2f}%")
print(f"Accuracy: {100 - accuracy:.2f}%")
