# 1. TCP Server

## Algorithm
1. Start and create a TCP socket.
2. Read the port number and initialize the server address.
3. Bind the socket to the server address.
4. Listen for client connections and accept a connection.
5. Receive and display the client's message.
6. Send a reply to the client.
7. Close both sockets and stop.

## Psuedocode 

START
Create TCP socket
IF socket creation fails
    Display error
    STOP
Read port number
Initialize server address
Bind socket to address
Listen for client connection
Accept client connection
Receive message from client
Display received message
Send reply to client
Close client socket
Close server socket
STOP


# 2. TCP Client

## Algorithm

1. Start and create a TCP socket.
2. Read the port number and initialize the server address.
3. Connect to the server.
4. Send a message to the server.
5. Receive and display the server's reply.
6. Close the socket and stop.

## Pseudocode

START
Create TCP socket
IF socket creation fails
    Display error
    STOP
Read port number
Initialize server address
Connect to server
Send message to server
Receive reply from server
Display received reply
Close client socket
STOP
