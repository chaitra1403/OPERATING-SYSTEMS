#include<stdio.h>
#include<stdlib.h>

int s=1,full=0,empty,x=0;
void producer()
{
  s=wait(s);
  full=signal(full);
  empty=wait(empty);
  x++;
  printf("\nProducer produces item %d",x);
  s=signal(s);
}

void consumer()
{
  s=wait(s);
  full=wait(full);
  empty=signal(empty);
  printf("\nConsumer consumes item %d",x);
  x--;
  s=signal(s);
}

int wait(int s)
{
  return --s;
}

int signal(int s)
{
  return (++s);
}

void main()
{
  int ch,n;
  printf("\nEnter size of buffer : ");
  scanf("%d",&n);
  empty=n;
  if(n<=0)
  {
    printf("\nEnter valid buffer size!");
    exit(0);
  }
  while(1)
  {
  printf("\n********************************\n");
  printf("\n1.Producer \n2.Consumer \n3.Exit\n");
  printf("\n********************************\n");

    printf("\nEnter choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
	case 1: if((s==1) && (empty!=0))
		  producer();
		else
		  printf("\nBuffer is full!");
		break;

	case 2: if((s==1) && (full!=0))
		  consumer();
		else
		  printf("\nBuffer is empty!");
		break;

	case 3: exit(0);

	default: printf("\nInvalid choice!");
		  break;
    }
  }
}

