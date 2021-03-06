import socket
import os

host = ''
port = 3000
backlog = 5
size = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host, port))
s.listen(backlog)


def echo(client, address):
    print('{}: connected'.format(address))
    data = client.recv(size).decode()
    while data:
        print('{}: {}'.format(address, data))
        client.send(data.upper().encode())
        data = client.recv(size).decode()
    print('{}: disconnected'.format(address))
    client.close()
    os._exit(0)


print('server is listening on port {}'.format(port))
while True:
    client, address = s.accept()

    if os.fork() == 0:
        echo(client, address)
