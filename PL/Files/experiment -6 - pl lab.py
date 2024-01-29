
import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost',12345)
client_socket.connect(server_address)

file_name='Sender_txt'

with open (file_name, 'rb') as file:
    while True:
        data = file.read(1024)
        if not data:
            break
        client_socket.send(data)
        
print (f"File '{file_name}' sent to the server.")

client_socket.close()