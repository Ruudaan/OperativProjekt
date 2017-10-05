#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
  pid_t pid;
  int n = 0;
  printf("How many times do you want to fork? ");
  scanf("%d",&n);

  for(int i = 0; i < n; i++)
   {
     fork();
     if(pid == 0)
     {
       execlp("./a", "a",NULL);
     }
   }

  return 0;
}
