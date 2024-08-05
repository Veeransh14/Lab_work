import random 

def display(room):
    print(room)
    
room = [[1,1],[1,1]]
display(room)

x=0
y=0

while x<2:
    while y<2:
        room[x][y] = random.choice([0,1])
        y+=1
    x+=1
    y=0
    
# detect the dirt
display(room)

x=0
y=0
z=0

while x<2:
    while y<2:
        if room[x][y] == 1:
            print("Vacuum at" ,x,y)
            room[x][y]=0
            print ("cleaned ",x,y)
            
            z+=1
        y+=1
    x+=1
    y=0
    
pro= (100-((z/4)*100))
print("room is clean")
display(room)
print ("performance", pro)