#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
	{
	int a=0,b=1,n=a+b,i;
	system("clear");
	pid_t pid=fork();
	if(pid<0)
	printf("Child is not created\n");

	if(pid==0)
		{
		printf("child is make the fibonacci\n");
		printf("Enter the number:");
		scanf("%d",&i);

		if(i==0)
		{
		printf(" 0 %d ",n);
		printf("\nChild ends\n");
		exit(1);
		}
		//n=a+b;
		printf(" 0 %d ",n);
		while(i>2)
			{
			n=a+b;
			printf(" %d ",n);
			//n=a+b;
			a=b;
			b=n;
			i--;
			if(i==2)
			printf("\nChild ends the process\n");
			}
		}
	else
		{
		printf("Parent is waiting for child to complete the process\n");
		waitpid(pid,NULL,0);

		}

	return 0;
	}

