#include <ctype.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <math.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>


#define N 5

void* producer(void* args);
void* consumer(void *args);
int removeItem();
int isFull();
void add(int item);
int front;
int rear;
int nrOfItems;
int items[5];
long int arr[5] = {0,1,2,3,4};

sem_t mutex;
sem_t empty;
sem_t full;
int main()
{

 srand (time(NULL));
   //sem_init(&sem, 0, 5);
  sem_init(&mutex,0,1);
  sem_init(&empty,0,N);
  sem_init(&full,0,0);
  front = -1;
  rear = -1;
  nrOfItems = 0;

  // pthread_mutex_init(&mutex,0);
   int prod, cons;
  printf("How many producers do u want? ");
  scanf("%d", &prod);
  printf("How many consumers do u want? ");
  scanf("%d", &cons);

  pthread_t *prodThreads = malloc(prod * sizeof(pthread_t));
  pthread_t *consThreads = malloc(cons * sizeof(pthread_t));

  for(int i = 0; i < prod; i++)
  pthread_create(&prodThreads[i],NULL,producer,(void*) arr[i]);

  for(int i = 0; i < cons; i++)
  pthread_create(&consThreads[i],NULL,consumer,(void*) arr[i]);

   for(int i = 0; i < prod; i++)
   pthread_join(prodThreads[i],NULL);
   for(int i = 0; i < cons; i++)
   pthread_join(consThreads[i],NULL);

  free(prodThreads);
  free(consThreads);
    return 0;
   }

   void* producer(void * args)
{
  int item;
  long int threadNr = (long int) args;

   while(1)
    {
    item = rand() % 10000;
    sem_wait(&empty);
    sem_wait(&mutex);
    add(item);
    //unsigned long int tid = pthread_self();
    printf("Producer nr: %ld produced item: %d \n",threadNr , item);
    sem_post(&mutex);
    sem_post(&full);
    int sleep2 = rand() % 5+1;

    sleep(sleep2);

    }

   return NULL;
}
   void* consumer(void* args)
  {
    long int threadNr = (long int) args;
    int item;

      while(1)
    {
    int sleep2 = rand() % 5+1;
    sem_wait(&full);
    sem_wait(&mutex);
    item = removeItem();
    //unsigned long int tid = pthread_self();
    printf("\t\t\t\t\t\tConsumer nr: %ld consumed item: %d \n",threadNr , item);
    sem_post(&mutex);
    sem_post(&empty);
    sleep(sleep2);
    }
      return NULL;
  }


  void add(int item)
  {

    if((front != 0 && rear != 5 - 1) || (front != rear+1))
   {
      if(rear == 5-1 && front != 0)
	     rear = -1;

      items[++rear] = item;
      if(front == -1)
	     front = 0;
       nrOfItems++;
    }
  }

  int removeItem()
  {
    int item;
    //printf("front: %d\n", front); printf("rear: %d\n", rear);
    if(front != -1 && rear != -1)
      {
      item = items[front++];
      if(front == 5)
	     front = 0;
      if(front-1 == rear)
	     front = rear = -1;
    }
    return item;
  }
