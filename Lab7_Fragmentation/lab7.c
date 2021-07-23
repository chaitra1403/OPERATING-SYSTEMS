#include<stdio.h>
void main()
{
int mem, size, blk, exterf,n, process[10],internalf=0;
int i,p=0;
printf("\n----------------------------------------------------------\n");
printf("Enter the total memory available  ");
scanf("%d",&mem);
printf("Enter the block size  ");
scanf("%d", &size);
blk=mem/size;
exterf=mem - blk*size;
printf("\nEnter the number of process ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter memory required for process %d  ",i+1);
scanf("%d",&process[i]);
}
printf("\nNo. of Blocks available in memory %d ",blk);
printf("\n----------------------------------------------------------\n");
printf("\n\nPROCESS\tMEMORYREQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION");
printf("\n----------------------------------------------------------\n");

for(i=0;i<n && p<blk;i++)
{
printf("\n %d\t\t%d",i+1,process[i]);
if(process[i] > size)
printf("\t\tNO\t\t---");
else
{
printf("\t\tYES\t%d",size-process[i]);
internalf = internalf + size-process[i];
p++;
}
}
if(i<n)
printf("\nMemory is Full, Remaining Processes cannot be accomodated");
printf("\n\nTotal Internal Fragmentation is %d",internalf);
printf("\nTotal External Fragmentation is %d\n",exterf);
}
