
#include <stdio.h>

int main()
{
    int n, window, lost, i, start = 0;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter window size: ");
    scanf("%d", &window);

    printf("Enter frame number to simulate loss (1-%d): ", n);
    scanf("%d", &lost);

    while(start < n)
    {
        int end = start + window;

        if(end > n)
            end = n;

        printf("\nSender sends frames: ");

        for(i = start; i < end; i++)
            printf("%d ", i + 1);

        printf("\n");

        if(lost > start && lost <= end)
        {
            printf("Frame %d is lost!\n", lost);
            printf("Receiver accepts and buffers other frames.\n");

            printf("ACK received for frames: ");

            for(i = start; i < end; i++)
            {
                if(i + 1 != lost)
                    printf("%d ", i + 1);
            }

            printf("\n");
            printf("Timeout for frame %d.\n", lost);
            printf("Retransmitting only frame %d.\n", lost);
            printf("Frame %d received successfully.\n", lost);
            printf("ACK %d received.\n", lost);

            lost = -1;
        }
        else
        {
            printf("Receiver received all frames correctly.\n");
            printf("ACK received for frames: ");

            for(i = start; i < end; i++)
                printf("%d ", i + 1);

            printf("\n");
        }

        start = end;
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}
