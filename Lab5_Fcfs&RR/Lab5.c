#include<stdio.h>
#include<stdlib.h>
int RRscheduling()		//Round Robin
{
        int n,at[10],bt[10],rt[10],wt=0,tat=0,count,remain,time,j,tq,flag=0;
        printf("Enter total process\n");	//Taking Number of process from user
        scanf("%d",&n);
        remain=n;
        for(count=0;count<n;count++)
        {
                printf("Enter arriaval time for process %d\n",count+1);		//Taking arrival time
		scanf("%d",&at[count]);
                printf("Enter burst time for process %d\n",count+1);		//Taking burst time
                scanf("%d",&bt[count]);
                rt[count]=bt[count];
        }
        printf("Enter Time Quantum\n");		//Taking Quantum time
        scanf("%d",&tq);
        printf("\nProcess\t\tTurnAroundTime\t\tWaitingTime\n");
        for(time=0,count=0;remain!=0;)		//for calculating turnaroung time and waiting time
        {
                if(rt[count]<=tq && rt[count]>0)
                {
                        time=time+rt[count];		//cputime
                        rt[count]=0;		//remainingtime
                        flag=1;
                }
                else if(rt[count]>0)
                {
                        rt[count]=rt[count]-tq;
                        time=time+tq;
                }
                if(rt[count]==0 && flag==1)
                {
                        remain--;
                        printf("\nP[%d]\t\t\t%d\t\t\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
                        wt=wt+time-at[count]-bt[count];
                        tat=tat+time-at[count];
                        flag=0;
		 }
                if(count==n-1)		//again pointing to the first position
                        count=0;
                else if(at[count+1]<=time)
                        count++;
                else
                        count=0;
        }
        printf("Average Turn Around Time=%f\n",(tat*1.0)/n);
        printf("Average Waiting Time=%f\n",(wt*1.0)/n);
        return 0;
}
void fcfs()
{
        int i,j,temp,temp1,np,wt[10],bt[10],ct[10],at[10],tat[10];
        float avgwt,avgtat;
        wt[0]=0;
        tat[0]=0;
        avgwt=0;
        avgtat=0;
        printf("\nEnter no of processes");
        scanf("%d",&np);
        for (i=0;i<np;i++)	//Taking inputs from user
        {
                printf("\nEnter p[%d] process details:-",i);
                printf("\n Enter arrival time");
                scanf("%d",&at[i]);
                printf("\n Enter burst time");
                scanf("%d",&bt[i]);
        }
        for(i=0;i<np;i++)		//arranging the processing according to arrival time
        {
                for(j=i+1;j<np;j++)
                {
                        if(at[i]>at[j])		//swaping arrival and burst time
                        {
                                temp1=at[i];
                                at[i]=at[j];
                                at[j]=temp1;
                                temp=bt[i];
                                bt[i]=bt[j];
                                bt[j]=temp;
                        }
                }
        }
        ct[0]=bt[0]+at[0];
        for(i=1;i<np;i++)		//calculating cputime(response time)
                ct[i]=bt[i]+ct[i-1];
        for(i=0;i<np;i++)		//calculating turn around time 
	{
                tat[i]=ct[i]-at[i];
        }
        for(i=0;i<np;i++)		//calculating waiting time
        {
                wt[i]=tat[i]-bt[i];
                if(wt[i]<0)
                {
                        j=i;
                        while(j<np){
                        tat[j]=tat[j]-wt[i];
                        ct[j]=ct[j]-wt[i];j++;}
                        wt[i]=0;
                }
        }
        for(i=0;i<np;i++)
        {
                avgwt=avgwt+wt[i];
                avgtat=avgtat+tat[i];
        }
	avgwt=avgwt/np;		//average waiting time
        avgtat=avgtat/np;	//average turn around time
        printf("\n \n Arrival time \t Burst time \t waiting time \t TAtime\t comp time\n");
        for(i=0;i<np;i++)
        {
                printf("\n\t%d\t \t %d\t\t%d\t%d\t %d",at[i],bt[i],wt[i],tat[i],ct[i]);
        }
        printf("\n\n Avg waiting time =\t%f",avgwt);
        printf("\n Avg Total turn around time =\t %f\n\n",avgtat);
}       
void main()
{
	int choice;
	while(1)
	{
		printf("\n 1. fcfs\n 2. Round Robin\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: fcfs();		//calling fcfs funtion
				break;
			case 2: RRscheduling();		//calling RRSchedulin function
				break;
			default:
				exit(0);
				break;
		}
	}
}
