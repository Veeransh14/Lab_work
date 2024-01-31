

import tkinter as tk
from tkinter import scrolledtext
import subprocess
import os

class Shell(tk.Tk):
   def __init__(self):
       super().__init__()
       self.user_info = os.environ['USER'] 
       self.machine_info = os.uname().nodename 
       self.title(f"Shell {self.user_info}@{self.machine_info}")
       self.create_widgets()

   def create_widgets(self):
       self.configure(bg="black")

       self.output_text = scrolledtext.ScrolledText(self, wrap=tk.WORD, width=160, height=34, bg="black", fg="white", insertbackground="white", font=("Courier", 15))
       self.output_text.grid(row=1, column=0, padx=10, pady=0, sticky="w", columnspan=3)

       self.command_entry = tk.Entry(self, width=80, bg="white", fg="black", insertbackground="black", relief=tk.FLAT,font=("Courier", 12))
       self.command_entry.grid(row=2, column=0, padx=10, pady=(0, 10), sticky="w", columnspan=3)

       self.command_entry.bind("<Return>", lambda event: self.execute_command())

       execute_button = tk.Button(self, text="Execute", command=self.execute_command, bg="#4E4E4E", fg="white", relief=tk.FLAT)
       execute_button.grid(row=3, column=0, pady=(0, 10), sticky="w", columnspan=3)

   def execute_command(self):
       command = self.command_entry.get()
       if command.lower() == 'exit':
           self.destroy()
           return
       self.command_entry.delete(0, tk.END)
      
       if command.startswith('cd '):
           new_dir = command.split(' ',1)[1]
           self.change_dir(new_dir)
           return

       if command.lower() == 'clear':
           self.output_text.delete(1.0,tk.END)
           return
      
       try:
           result = subprocess.check_output(['bash', '-c', command], stderr=subprocess.STDOUT, text=True)
       except subprocess.CalledProcessError as e:
           result = e.output

       prompt_text = f"{self.user_info}@{self.machine_info}:~{os.getcwd()}$"
       self.output_text.insert(tk.END, f"{prompt_text} {command}\n{result}\n\n")
       self.output_text.see(tk.END)
      
   def change_dir(self, new_dir):
       try:
           os.chdir(new_dir)
           prompt_text = f"{self.user_info}@{self.machine_info}:~{os.getcwd()}$ \n\n"
       except FileNotFoundError:
           prompt_text = f"{self.user_info}@{self.machine_info}:~{os.getcwd()}$ \n{new_dir}: No such file or directory \n\n"
       self.output_text.insert(tk.END, f"{prompt_text}")
       self.output_text.see(tk.END)   
      
          

if __name__ == "__main__":
   app = Shell()
   app.mainloop()

