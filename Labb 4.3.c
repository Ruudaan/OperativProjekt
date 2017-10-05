#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int a = 0;
  while (1)
  {
    printf("Fork! %d\n",a);
    a++;
  }

  getchar();
  return 0;
}
