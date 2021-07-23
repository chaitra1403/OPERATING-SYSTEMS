#include<stdio.h>
#include<stdlib.h>
void fcfs();
void scan();
void cscan();
void look();
void sstf();
void main()
{
	while(1)
	{
		int choice;
		printf("----------------\n");
		printf("1-FCFS \n");
	        printf("2-SCAN \n");
		printf("3-C-SCAN \n");
		printf("4-LOOK \n");
		printf("5-SSTF \n");
		printf("6-Exit \n");
		printf("----------------\n");
		printf("enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: fcfs();
			break;
			case 2: scan();
        		break;
			case 3: cscan();
        		break;
			case 4: look();
        		break;
			case 5: sstf();
        		break;
			case 6:
			exit(0);
			default: printf("invalid choice");
		}

	}
}


void fcfs()
{
	int queue[20],n,head,i,j,k,seek=0,diff;
	float avg;
	printf("Enter the size of queue request\n");
	scanf("%d",&n);
	printf("Enter the queue of disk positions to be read\n");
	for(i=1;i<=n;i++)
	scanf("%d",&queue[i]);
	printf("Enter the initial head position\n");
	scanf("%d",&head);
	queue[0]=head;
	for(j=0;j<=n-1;j++)
	{
		diff=abs(queue[j+1]-queue[j]);
		seek +=diff;
		printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
	}
	printf("Total seek time is %d\n",seek);
	avg=seek/(float)n;
	printf("Average seek time is %f\n",avg);
}
void scan()
{
	int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp1=0,temp2=0;
            float avg;
            printf("Enter the max range of disk\n");
            scanf("%d",&max);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            printf("Enter the size of queue request\n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]<queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            queue[i]=queue1[j];
            queue[i]=max;
            for(i=temp1+2,j=0;j<temp2;i++,j++)
            queue[i]=queue2[j];
            queue[i]=0;
            queue[0]=head;
            for(j=0;j<=n;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek +=diff;
                        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
            }
            printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %f\n",avg);
}



void cscan()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],
                        temp1=0,temp2=0;
            float avg;
            printf("Enter the max range of disk\n");
            scanf("%d",&max);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            printf("Enter the size of queue request\n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    queue1[temp1]=temp;
                                    temp1++;
                        }
                        else
                        {
                                    queue2[temp2]=temp;
                                    temp2++;
                        }
            }
            for(i=0;i<temp1-1;i++)
            {
                        for(j=i+1;j<temp1;j++)
                        {
                                    if(queue1[i]>queue1[j])
                                    {
                                                temp=queue1[i];
                                                queue1[i]=queue1[j];
                                                queue1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<temp2-1;i++)
            {
                        for(j=i+1;j<temp2;j++)
                        {
                                    if(queue2[i]>queue2[j])
                                    {
                                                temp=queue2[i];
                                                queue2[i]=queue2[j];
                                                queue2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<temp1;i++,j++)
            queue[i]=queue1[j];
            queue[i]=max;
            queue[i+1]=0;
            for(i=temp1+3,j=0;j<temp2;i++,j++)
            queue[i]=queue2[j];
            queue[0]=head;
            for(j=0;j<=n+1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek +=diff;
                        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);
            }
            printf("Total seek time is %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time is %f\n",avg);
}

void look()
{
    int i,n,j=0,k=0,x=0,l,req[50],mov=0,cp,end, lower[50],upper[50], temp,a[50];
    float avg;
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    /*break the request array into two arrays : one with requests lower than current and other with requests higher than current position. Also sort these two new arrays*/
    for(i=0;i<n;i++)
    {
        if(req[i]<cp)
        {
            lower[j]=req[i];
            j++;
        }
        if(req[i]>cp)
        {
            upper[k]=req[i];
            k++;
        }
    }
    //sort the lower array in reverse order
    for(i=0;i<j;i++)
    {
        for(l=0;l<j-1;l++)
        {
            if(lower[l]<lower[l+1])
            {
                temp=lower[l];
                lower[l]=lower[l+1];
                lower[l+1]=temp;
            }
        }
    }
    // sort the upper array in ascending order
    for(i=0;i<=k;i++)
    {
        for(l=0;l<k-1;l++)
        {
            if(upper[l]>upper[l+1])
            {
                temp=upper[l];
                upper[l]=upper[l+1];
                upper[l+1]=temp;
            }
        }
    }
    printf("Enter the end to which the head is moving (0 - for lower end(zero) and 1 - for upper end\n");
    scanf("%d",&end);
    switch(end)
    {
        case 0:
            for(i=0;i<j;i++)
            {
                a[x]=lower[i];
                x++;
            }
            for(i=0;i<k;i++)
            {
                a[x]=upper[i];
                x++;
            }
        break;
        case 1:
            for(i=0;i<k;i++)
            {
                a[x]=upper[i];
                x++;
            }
            for(i=0;i<j;i++)
            {
                a[x]=lower[i];
                x++;
            }
        break;
    }
    mov=mov+abs(cp-a[0]);
    printf("%d -> %d",cp,a[0]);
    for(i=1;i<x;i++)
    {
        mov=mov+abs(a[i]-a[i-1]);
        printf(" -> %d",a[i]);
    }
    printf("\n");
    printf("total seak time = %d\n",mov);

    avg=mov/(float)n;

    printf("Average seek time is %f\n",avg);

}



void sstf()
{
    int i,n,k,req[50],mov=0,cp,index[50],min,a[50],j=0,mini,cp1;
    float avg=0.0;
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    cp1=cp;
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    for(k=0;k<n;k++){
    for(i=0;i<n;i++)
    {
        index[i]=abs(cp-req[i]); // calculate distance of each request from current position
    }
    // to find the nearest request
    min=index[0];
    mini=0;
    for(i=1;i<n;i++)
    {
        if(min>=index[i])
        {
	   if(min==index[i]&&(req[i]<cp)){
		continue;}
	   else
	   {
            min=index[i];
            mini=i;
	   }
        }
    }
    a[j]=req[mini];
    j++;
    cp=req[mini]; // change the current position value to next request
    req[mini]=999; // the request that is processed its value is changed so that it is not processed again
    }
    printf("Sequence is : ");
    printf("%d",cp1);
    mov=mov+abs(cp1-a[0]);    // head movement
    printf(" -> %d",a[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(a[i]-a[i-1]); ///head movement
        printf(" -> %d",a[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
    avg=mov/n;
    printf("average seek time = %f\n",avg);
}







