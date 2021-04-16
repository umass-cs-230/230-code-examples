# This requires python3.

from socket import *

serverName = 'localhost'
serverPort = 3000

# Create a socket of Address family AF_INET.
print('Echo Client is creating a socket.')
clientSocket = socket(AF_INET, SOCK_STREAM)

# Client socket connection to the server
print('Echo Client is trying to connect to {} ({}:{}).'.format(
    serverName, gethostbyname(serverName), serverPort))
clientSocket.connect((serverName, serverPort))

print('Echo Client connected.')

# Create data to be sent
sentence = input('type: ')

while not sentence == 'quit':
    # Send the data to the server
    clientSocket.send(sentence.encode())

    # Receive 1024 bytes of data.
    resp = clientSocket.recv(1024)

    # Display data from server.
    print('echo ({} bytes): {}'.format(len(resp), resp.decode()))

    sentence = input('type: ')

# Close socket connection
clientSocket.close()
