
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addr_size;
    char buffer[1024];
    int port;

    // Create UDP socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if(serverSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Enter Port Number: ");
    scanf("%d", &port);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    bind(serverSocket, (struct sockaddr *)&serverAddr,
         sizeof(serverAddr));

    printf("\nWaiting for client connection...\n");

    addr_size = sizeof(clientAddr);

    // Receive message from client
    recvfrom(serverSocket, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&clientAddr, &addr_size);

    buffer[strlen(buffer)] = '\0';

    printf("Client Connected Successfully.\n");
    printf("\nMessage received from Client: %s\n", buffer);

    // Send reply to client
    strcpy(buffer, "YOUR MESSAGE RECEIVED");

    sendto(serverSocket, buffer, strlen(buffer) + 1, 0,
           (struct sockaddr *)&clientAddr, addr_size);

    close(serverSocket);

    return 0;
}
