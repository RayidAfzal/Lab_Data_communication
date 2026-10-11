
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int port;

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Enter port number: ");
    scanf("%d", &port);

    // Server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // Localhost
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("\nTrying to connect...\n");

    // Connect to server
    if (connect(clientSocket,
                (struct sockaddr *)&serverAddr,
                sizeof(serverAddr)) < 0)
    {
        printf("Connection failed\n");
        close(clientSocket);
        return 0;
    }

    printf("Connected Successfully\n");

    // Send message to server
    strcpy(buffer, "HI I AM CLIENT");
    write(clientSocket, buffer, strlen(buffer) + 1);

    // Receive reply from server
    memset(buffer, 0, sizeof(buffer));
    read(clientSocket, buffer, sizeof(buffer) - 1);

    printf("\nMessage from server: %s\n", buffer);

    close(clientSocket);

    return 0;
}
