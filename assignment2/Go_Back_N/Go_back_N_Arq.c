
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

        /* Check whether lost frame is in current window */
        if(lost > start && lost <= end)
        {
            printf("Frame %d is lost!\n", lost);
            printf("Receiver discards frames from %d onward.\n", lost);
            printf("Timeout occurred for frame %d.\n", lost);

            printf("Retransmitting frames: ");

            for(i = lost - 1; i < end; i++)
                printf("%d ", i + 1);

            printf("\n");

            printf("ACK received for frames %d to %d.\n",
                   lost, end);

            start = end;
            lost = -1;
        }
        else
        {
            printf("Receiver received all frames correctly.\n");
            printf("ACK received for frames %d to %d.\n",
                   start + 1, end);

            start = end;
        }
    }

    printf("\nAll frames transmitted successfully.\n");

    return 0;
}
