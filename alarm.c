#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
  printf("/\nAlarm Triggered!\n):
}

int main()
{
  signal(SIGALARM, handler);
  alarm(5);
  printf("Waiting for alarm.......\n");
  while(1);

  return 0;
}
  
