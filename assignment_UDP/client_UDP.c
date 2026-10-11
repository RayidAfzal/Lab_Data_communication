
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int clientSocket;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;
    char buffer[1024];
    int port;

    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);

    if (clientSocket < 0)
    {
        printf("Socket creation failed\n");
        return 0;
    }

    printf("Enter Port Number: ");
    scanf("%d", &port);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    addr_size = sizeof(serverAddr);

    printf("\nTrying to connect...\n");

    strcpy(buffer, "HI, I AM RAYID...");
    sendto(clientSocket, buffer, strlen(buffer) + 1, 0,
           (struct sockaddr *)&serverAddr, addr_size);

    printf("Message sent successfully.\n");

    recvfrom(clientSocket, buffer, sizeof(buffer) - 1, 0,
             (struct sockaddr *)&serverAddr, &addr_size);

    printf("\nMessage from server: %s\n", buffer);

    close(clientSocket);

    return 0;
}
