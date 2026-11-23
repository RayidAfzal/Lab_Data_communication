#include <stdio.h>
#include <unistd.h>

#define NOF_PACKETS 10

int main()
{
    int packet_sz[NOF_PACKETS] = {40, 20, 60, 30, 50, 10, 40, 20, 30, 50};
    int i, clk, b_size, o_rate;
    int p_sz_rm = 0;
    int p_time, op;

    // Display packet sizes
    for(i = 0; i < NOF_PACKETS; i++)
        printf("\nPacket[%d]: %d Bytes", i, packet_sz[i]);

    printf("\nEnter the bucket size: ");
    scanf("%d", &b_size);

    printf("Enter the output rate: ");
    scanf("%d", &o_rate);

    // Process each packet
    for(i = 0; i < NOF_PACKETS; i++)
    {
        if((packet_sz[i] + p_sz_rm) > b_size)
        {
            if(packet_sz[i] > b_size)
            {
                printf("\nIncoming packet size (%d bytes) is greater than bucket capacity (%d bytes). PACKET REJECTED",
                       packet_sz[i], b_size);
            }
            else
            {
                printf("\nBucket capacity exceeded. PACKET REJECTED!!");
            }
        }
        else
        {
            p_sz_rm += packet_sz[i];

            printf("\n\nIncoming packet size: %d", packet_sz[i]);
            printf("\nBytes remaining to transmit: %d", p_sz_rm);

            p_time = 30;  // Fixed transmission time

            printf("\nTime left for transmission: %d units", p_time);

            for(clk = 10; clk <= p_time; clk += 10)
            {
                sleep(1);

                if(p_sz_rm)
                {
                    if(p_sz_rm <= o_rate)
                    {
                        op = p_sz_rm;
                        p_sz_rm = 0;
                    }
                    else
                    {
                        op = o_rate;
                        p_sz_rm -= o_rate;
                    }

                    printf("\nPacket of size %d Transmitted", op);
                    printf("\n----Bytes remaining to transmit: %d", p_sz_rm);
                }
                else
                {
                    printf("\nTime left for transmission: %d units", p_time - clk);
                    printf("\nNo packets to transmit!!");
                }
            }
        }
    }

    return 0;
}
