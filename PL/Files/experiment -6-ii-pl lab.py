
import socket 

server_socket= socket.socket (socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost',12345)
server_socket.bind(server_address)

server_socket.listen(1)
print("Server is listening for incoming connections...")

client_socket, client_address = server_socket.accept()
print(f"Connections from{client_address} established.")

file_name = 'Reciever.txt'
with open (file_name, 'wb') as file:
    while True:
        data= client_socket.recv(1024)
        if not data:
            break
        file.write(data)
        
print (f"File recieved and save as {file_name}")

with open (file_name, 'r') as file:
    file_contents = file.read()
    print("File contests: ")
    print(file_contents)
    
client_socket.close()
server_socket.close()
    