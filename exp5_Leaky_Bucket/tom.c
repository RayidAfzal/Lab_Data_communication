#include <stdio.h>
#include <stdlib.h>
int main()
{
 int bucket, rate, packet;
 int remaining = 0, i;
 printf("Enter bucket capacity: ");
 scanf("%d", &bucket);
 printf("Enter output rate: ");
 scanf("%d", &rate);
 for(i = 1; i <= 5; i++)
 {
 packet = (rand() % 5 + 1) * 10;
 printf("\nIncoming packet: %d", packet);
 if(remaining + packet > bucket)
 {
 printf("\nPacket rejected");
 }
 else
 {
 remaining = remaining + packet;
 printf("\nPacket accepted");
 }
 if(remaining > 0)
 {
 if(remaining <= rate)
 {
 printf("\nTransmitted: %d", remaining);
 remaining = 0;
 }
 else
 {
 printf("\nTransmitted: %d", rate);
 remaining = remaining - rate;
 }
 }
 printf("\nRemaining: %d\n", remaining);
 }
 return 0;
}
