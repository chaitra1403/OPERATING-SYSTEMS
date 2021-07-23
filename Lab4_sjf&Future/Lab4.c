#include<stdio.h>
#include<stdlib.h>
float  p[20],min, btime = 0;
float bt[20], temp, at[20], atWithIdle[20], ct[20],wt[20], tat[20], sum = 0;
int idleTime = 0,ct1=0,i,ch, n,j,k=1,i1;
float avgwt = 0, avgtat = 0, tsum = 0, wsum = 0,time;

void swap(float *xp, float *yp)  // used for swapping 
{
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void take(){   // used to take input from user
    printf("\nEnter the No. of processes :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\tEnter the burst time of p[%d] process :", i + 1);
        scanf(" %f", &bt[i]);
        printf("\tEnter the arrival time of p[%d] process :", i + 1);
        scanf(" %f", &at[i]);
        atWithIdle[i] = at[i];
    }
}

void pSwap(){
    btime = at[0];  // take var btime and assign the first index vale of arrival time
    for (j = 0; j < n; j++)
    {
        btime = btime + bt[j];
        min = bt[k];
        for (i = k; i < n; i++)
        {
            if (btime >= atWithIdle[i] && bt[i] < min)
            {
                swap(&p[i],&p[k]);  // swap process id
		 swap(&at[i],&at[k]);  //swap arrival time
                swap(&bt[i],&bt[k]);  // swap burst time
                swap(&atWithIdle[i],&atWithIdle[k]);  // swap atWithIdle time
            }
        }
        k++;
    }
}
void result(){		//Printing Result
    ct1 = atWithIdle[0];
    wt[0]=0;
    printf("\nPid \t AT \t BT \t CT \t WT \t TAT");
    for(i=0;i<n;i++)
    {
        ct1=ct1+bt[i];
        tat[i]=ct1-at[i];
        wt[i] = tat[i]-bt[i];
        tsum=tsum+tat[i];
        wsum=wsum+wt[i];
        printf("\np[%d]\t %f\t %f\t %d \t %f\t %f",i,at[i],bt[i],ct1,wt[i],tat[i]);
	 }    
    avgtat=(tsum/n); 
    avgwt = (wsum / n);     
    printf("\n\nAVERAGE WAITING TIME : %f", avgwt);
    printf("\nAVERAGE TURN AROUND TIME : %f", avgtat);
}
void futureMethod(){
    printf("Input for Future knowledge\n");
    take();  // input method envoked
    printf("\nEnter idle time :");
    scanf("%d", &idleTime);
    /*Sort according to Arrival Time*/
    for (i = 0; i < n; i++)
    {
        if (at[i] < idleTime)  //check for arrival time is less than idle time if yes assign arrivalWithIdle time equals user idle time
        {
            atWithIdle[i] = idleTime;
       }
    }
   for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (atWithIdle[i] < atWithIdle[j])  // comparing the arrivalWithIdle time
            {
                swap(&p[i],&p[j]);   // swap process id
                swap(&at[i],&at[j]); //swap arrival time
                swap(&bt[i],&bt[j]); // swap burst time
                swap(&atWithIdle[i],&atWithIdle[j]);  // also swap atWithIdle time if (atWithIdle[i] < atWithIdle[j]) true
            }
            else if ((atWithIdle[i] == atWithIdle[j]) && (bt[i] < bt[j])) // Sort based on burst time for processes with same arrival time
            {
                swap(&p[i],&p[j]);  // swap process id
                swap(&at[i],&at[j]); //swap arrival time
                swap(&bt[i],&bt[j]); // swap burst time
                swap(&atWithIdle[i],&atWithIdle[j]);  // swap atWithIdle time
            }
        }
    }
	pSwap();	//calling pswap function
	result();	//calling result function
}
void sjf()
{
        printf("\nenter total no of process");		//Taking inputs from user
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nEnter arrival time for process p[%d] is :-",i+1);
                scanf("%f",&at[i]);
                printf("\n Enter burst time for process p[%d] is :-",i+1);
                scanf("%f",&bt[i]);
        }
        printf("\n \t Arrival time\t\tBurst Time\t\tcpu time\t\twaiting time\t\tTurnaround time\n");
        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(at[i]>at[j])
                        {
       				swap(&at[i],&at[j]);		//swaping arrival time
				swap(&bt[i],&bt[j]);		//swaping burst time
                        }}}
        if(at[0]!=0)
        {k=0;
        }
        else{
                for(i=0;i<n;i++)
                        for(j=i+1;j<n;j++)
                                if(at[i]==at[i+1])
                                if(bt[i]>bt[i+1])
                                {
						swap(&at[i],&at[j]);	//swaping arrival time
						swap(&bt[i],&bt[j]);	//swaping burst time
                                }
                k=1;
        }
        for(i=k;i<n;i++)
        {
                for(j=i;j<n;j++)
                {
                        if(k==0)
                                time=bt[k];
                        else
                                time=bt[k-1];
                        if(time>=1)
                        {
                                if(at[j]<=time)
                                {
                                        if(bt[i]>bt[j])
                                        {
						swap(&at[i],&at[j]);	//swaping arrival time
						swap(&bt[i],&bt[j]);	//swaping burst time
                                        }
                                }
                        }

                }
        }

        ct[0]=at[0]+bt[0];
        for(i=1;i<n;i++)
                ct[i]=ct[i-1]+bt[i];	//calculating cputime
        for(i=0;i<n;i++){
                tat[i]=ct[i]-at[i];}	//calculating turn around time
	 for(i=0;i<n;i++){
                wt[i]=tat[i]-bt[i];	//calculating waiting time
                if(wt[i]<0)
                {
                        int k = i;
                        while(k<n){
                                ct[k]=ct[k]-wt[i];
                                tat[k]=tat[k]-wt[i];
                                k++;}
                        wt[i]=0;
                }
        }
        for(i=0;i<n;i++)
        {
                avgwt=avgwt+wt[i];
                avgtat=avgtat+tat[i];
        }
        avgwt=avgwt/n;	//average waiting time
        avgtat=avgtat/n;	//average turn around time
        for(i=0;i<n;i++)
	{
                printf("\t %f\t\t%f\t\t%f\t\t%f\t\t%f\n",at[i],bt[i],ct[i],wt[i],tat[i]);	//Displaying Result
        }
        printf("The  average waiting time is %f\t\n",avgwt);
        printf("The Average turn Ariund Time is %f \t\n", avgtat);
}
void main()
{
   while(1){
		printf("\n 1. sjf \n 2. Future Knowledge \n");
		printf("Enter ur choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			sjf();	//calling sjf function
			break;
		case 2:
			futureMethod();	//calling futureMethod function
			break;
		default:
                	exit(0);
			break;
		}
	}
}
