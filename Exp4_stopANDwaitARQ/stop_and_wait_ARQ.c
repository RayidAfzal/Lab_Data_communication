
#include <stdio.h>

int main()
{
    int n, i;
    int ack;

    printf("Enter Number of frames: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("\nSending Frame %d", i);

        printf("\nEnter ACK for Frame %d (1=Received, 0=Lost): ", i);
        scanf("%d", &ack);

        if(ack == 1)
        {
            printf("ACK %d received.", i);
            printf("\nSending next frame...");
        }
        else
        {
            printf("Frame %d Lost.", i);
            printf("\nRetransmitting Frame %d...", i);

            printf("\nEnter ACK for Frame %d after retransmission (1=Received): ", i);
            scanf("%d", &ack);

            if(ack == 1)
            {
                printf("ACK %d Received.", i);
                printf("\nSending next frame...");
            }
            else
            {
                printf("Frame %d could not be transmitted successfully.", i);
            }
        }
    }

    printf("\n\nAll frames transmitted successfully.\n");

    return 0;
}
