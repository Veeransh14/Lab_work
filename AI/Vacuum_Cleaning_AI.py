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

def update(frame):
    global cleaned_cells
    for x in range(n):
        for y in range(m):
            if room[x][y] == 1:
                room[x][y] = 0
                cleaned_cells += 1
                cax.set_data(room)
                ax.set_title(f"Cleaned: {cleaned_cells}/{total_cells} cells")
                plt.pause(0.1)
    return [cax]

ani = animation.FuncAnimation(fig, update, frames=n*m, blit=False, repeat=False)

plt.colorbar(cax)
plt.show()

performance = (cleaned_cells / total_cells) * 100
print("Final room state:")
display(room)
print("Performance:", performance)
