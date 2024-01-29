
# Import Module

from tkinter import *



root = Tk()
root.title("Calculator")
root.geometry("300x350")

text=Entry(root,font=("calibri",16))
text.pack(fill=X,padx=25,ipadx=25,ipady=25)

def addToText(n):
    text.insert(END,n)

def calculate():
   result = eval(text.get())
   text.delete(0,END)
   text.insert(0,result)

def clear():
     text.delete(0,END)

# Text Bar
frame=Frame(root)
frame.pack(side=TOP,anchor=NW)

# CLEAR ICON    
rightFrame=Frame(frame)
rightFrame.pack(side=RIGHT)

frame1=Frame(frame)
frame1.pack()

# Number Row 1
btn1 = Button(frame1,text="1",width=9,height=3,command=lambda:addToText("1"))
btn1.pack(side=LEFT)
btn2 = Button(frame1,text="2",width=9,height=3,command=lambda:addToText("2"))
btn2.pack(side=LEFT)
btn3 = Button(frame1,text="3",width=9,height=3,command=lambda:addToText("3"))
btn3.pack(side=LEFT)


frame2=Frame(frame)
frame2.pack()

# Number Row 2
btn4= Button(frame2,text="4",width=9,height=3,command=lambda:addToText("4"))
btn4.pack(side=LEFT)
btn5 = Button(frame2,text="5",width=9,height=3,command=lambda:addToText("5"))
btn5.pack(side=LEFT)
btn6 = Button(frame2,text="6",width=9,height=3,command=lambda:addToText("6"))
btn6.pack(side=LEFT)


frame3=Frame(frame)
frame3.pack()

# Number Row 3
btn7= Button(frame3,text="7",width=9,height=3,command=lambda:addToText("7"))
btn7.pack(side=LEFT)
btn8= Button(frame3,text="8",width=9,height=3,command=lambda:addToText("8"))
btn8.pack(side=LEFT)
btn9 = Button(frame3,text="9",width=9,height=3,command=lambda:addToText("9"))
btn9.pack(side=LEFT)

frame4=Frame(frame)
frame4.pack()

btnpt= Button(frame4,text=".",width=9,height=3,command=lambda:addToText("."))
btnpt.pack(side=LEFT)
btn0= Button(frame4,text="0",width=9,height=3,command=lambda:addToText("0"))
btn0.pack(side=LEFT)
btneq = Button(frame4,text="=",width=9,height=3,command=lambda:calculate())
btneq.pack(side=LEFT)


btndiv = Button(rightFrame,text="/",width=9,height=3,command=lambda:addToText("/"))
btndiv.pack()
btnmul = Button(rightFrame,text="x",width=9,height=3,command=lambda:addToText("*"))
btnmul.pack()
btnsub= Button(rightFrame,text="-",width=9,height=3,command=lambda:addToText("-"))
btnsub.pack()
btnadd = Button(rightFrame,text="+",width=9,height=3,command=lambda:addToText("+"))
btnadd.pack()

btn123 = Button(rightFrame,text="Clear",width=9,height=3,command=lambda:clear())
btn123.pack()


root.mainloop()