#include <stdio.h>
int main()
{
 int cost[10][10], dist[10][10];
 int n, i, j, k, count;
 printf("Enter number of routers: ");
 scanf("%d", &n);
 printf("Enter cost matrix:\n");
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 {
 scanf("%d", &cost[i][j]);
 dist[i][j] = cost[i][j];
 }
 }
 do
 {
 count = 0;
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 {
 for(k = 0; k < n; k++)
 {
 if(dist[i][j] > cost[i][k] + dist[k][j])
 {
 dist[i][j] = cost[i][k] + dist[k][j];
 count++;
 }
 }
 }
 }
 } while(count != 0);
 printf("\nShortest distance matrix:\n");
 for(i = 0; i < n; i++)
 {
 for(j = 0; j < n; j++)
 printf("%d\t", dist[i][j]);
 printf("\n");
 }
 return 0;
}
