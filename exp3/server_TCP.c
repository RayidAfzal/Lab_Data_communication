
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    char buffer[1024];
    int port;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Enter Port Number: ");
    scanf("%d", &port);

    // Server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(serverSocket,
         (struct sockaddr *)&serverAddr,
         sizeof(serverAddr));

    // Listen
    listen(serverSocket, 5);

    printf("\nWaiting for client connection...\n");

    addr_size = sizeof(clientAddr);

    // Accept
    clientSocket = accept(serverSocket,
                          (struct sockaddr *)&clientAddr,
                          &addr_size);

    printf("Client Connected Successfully\n");

    // Read message from client
    memset(buffer, 0, sizeof(buffer));
    read(clientSocket, buffer, sizeof(buffer) - 1);

    printf("\nMessage received from client: %s\n", buffer);

    // Send reply to client
    strcpy(buffer, "YOUR MESSAGE RECEIVED");
    write(clientSocket, buffer, strlen(buffer) + 1);

    close(clientSocket);
    close(serverSocket);

    return 0;
}
