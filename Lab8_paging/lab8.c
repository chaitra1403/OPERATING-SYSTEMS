#include<stdio.h>

void fifo()
{
 int i,j,n,a[50],frame[10],nof,k,avail,count=0;
 printf("\nEnter number of pages : ");
 scanf("%d",&n);
 printf("\nEnter page number/reference string : ");
 for(i=1;i<=n;i++)  
  scanf("%d",&a[i]);
 
 printf("\nEnter number of frames : ");
  scanf("%d",&nof);
 
 for(i=0;i<nof;i++)
   frame[i]=-1;
 	j=0;
	printf("\n\tReference string \t Page frames \n");
	for(i=1;i<=n;i++)
	{
	  printf("\t %d \t",a[i]);
	  avail=0;
	  for(k=0;k<nof;k++)
	   if(frame[k]==a[i])
		avail=1;
	   if(avail==0)
	   {
		frame[j]=a[i];
		j=(j+1)%nof;
		count++;
		for(k=0;k<nof;k++)
			printf("%d\t",frame[k]);
	    }
	    printf("\n");
	}
	printf("\nPage fault is %d\n",count);
}

void optimal()
{
 int i,nof,nop,frames[10],pages[30],temp[30],flag1,flag2,flag3,j,k,pos,max,faults=0;
 printf("\nEnter number of pages : ");
  scanf("%d",&nop);
   printf("\nEnter page number/reference string : ");
   for(i=0;i<nop;i++)
    scanf("%d",&pages[i]);
  
   printf("\nEnter number of frames : ");
    scanf("%d",&nof);
  
   for(i=0;i<nof;i++)
     frames[i]=-1;

   for(i=0;i<nop;i++)
   {
	flag1=flag2=0;
	for(j=0;j<nof;j++)
	{
	  if(frames[j]==pages[i])
	   {
		flag1=flag2=1;
		break;
	   }
	}
	if(flag1==0)
	{
	  for(j=0;j<nof;j++)
	  {
		if(frames[j]==-1)
		{
		  faults++;
		  frames[j]=pages[i];
		  flag2=1;
		  break;
		}
	  }
	}
	
	if(flag2==0)
	{
	  flag3=0;
	  for(j=0;j<nof;j++)
	  {
		temp[j]=-1;
		for(k=i+1;k<nop;k++)
		{
		  if(frames[j]==pages[k])
		  {
			temp[j]=k;
			break;
		  }
		}
	  }
	
	for(j=0;j<nof;j++)
	{
	  if(temp[j]==-1)
	  {
		pos=j;
		flag3=1;
		break;
	  }
	}

	if(flag3==0)
	{
	  max=temp[0];
	  pos=0;
	  for(j=1;j<nof;j++)
	  {
		if(temp[j]>max)
		{
			max=temp[j];
			pos=j;
		}
	  }
	}

	frames[pos]=pages[i];
	faults++;
	}
	printf("\n");
	for(j=0;j<nof;j++)
	printf("%d\t",frames[j]);
 }
printf("Total number of page faults is %d ",faults);
}

int findlru(int time[],int n)
{
  int i,minimum=time[0],pos=0;
  for(i=0;i<n;i++)
  {
	if(time[i]<minimum)
	{
		minimum=time[i];
		pos=i;
	}
   }
   return pos;
}

void lru()
{
  int nof,nop,frames[10],pages[30],count=0,time[10],flag1,flag2,i,j,pos,faults=0;
  printf("\nEnter number of pages : ");
  scanf("%d",&nop);
  printf("\nEnter page number/reference string : ");
  for(i=0;i<nop;i++)
   scanf("%d",&pages[i]);
 
  printf("\nEnter number of frames : ");
  scanf("%d",&nof);

  for(i=0;i<nof;i++)
	frames[i]=-1;
 
  for(i=0;i<nop;i++)
  {
     flag1=flag2=0;
     for(j=0;j<nof;j++)
     {
	if(frames[j]==pages[i])
	{
	 count++;
	 time[j]=count;
	 flag1=flag2=1;
	 break;
	}
      }
     
     if(flag1==0)
     {
	for(j=0;j<nof;j++)
	{
	  if(frames[j]==-1)
	  {
	    count++;
	    faults++;
		frames[j]=pages[i];
		time[j]=count;
		flag2=1;
		break;
	   }
	}
      }
	
	if(flag2==0)
	{
	 pos=findlru(time,nof);
	 count++;
	 faults++;
	 frames[pos]=pages[i];
	 time[pos]=count;
	}
	printf("\n");

	for(j=0;j<nof;j++)
	 printf("%d\t",frames[j]);
	}
  printf("\n\nTotal page faults is %d",faults);
}


void main()
{
  int ch;
  do
{
  printf("\n1.Fifo \n2.LRU \n3.Optimal \n4.Exit \nenter choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
	case 1: fifo();
		break;

	case 2: lru();
		break;

	case 3: optimal();
		break;

	case 4: break;

	default: printf("\nInvalid choice!");
		 break;
   }
}while(ch!=4);
}


