#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct fileTable
{
	char name[20];
	int nob;
	struct block *sb;
}ft[30];
struct block
{
	int bno;
	struct block *next;
};
void main()
{
	int i, j, n;
	char s[20];
	struct block *temp,*t2;
	printf("Enter no of files :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter file name %d:",i+1);
		scanf("%s",ft[i].name);
		printf("Enter no of blocks in file %d :",i+1);
		scanf("%d",&ft[i].nob);
		ft[i].sb=(struct block*)malloc(sizeof(struct block));
		temp = ft[i].sb;
		printf("Enter the start of blocks of the file :");
		scanf("%d",&temp->bno);
		temp->next=NULL;
		for(j=1;j<ft[i].nob;j++)
		{
			temp->next = (struct block*)malloc(sizeof(struct block));
			temp = temp->next;
			printf("Enter block occupied");
			scanf("%d",&temp->bno);
		}
		temp->next = NULL;
	}
	for(i=0;i<n;i++)
	{
		temp=ft[i].sb;
		for(j=i+1;j<n;j++)
		{
			t2=ft[j].sb;
			int k=0;
			while(k<ft[i].nob)
			{
				int l=0;
				while(l<ft[j].nob)
				{
					if(temp->bno==t2->bno)
					{
						printf("Block occupied \n");
						exit(0);
					}
					l++;
					if(t2->next!=NULL)
					t2=t2->next;
				}
				k++;
				if(temp->next!=NULL)
				temp=temp->next;
			}
		}
	}
				
			
		
	printf("\nEnter the file name to be searched -- ");
	scanf("%s",s);
	for(i=0;i<n;i++)
		if(strcmp(s, ft[i].name)==0)
			break;
	if(i==n)
		printf("\nFile Not Found");
	else
	{
		printf("\nFILE NAME\t NO OF BLOCKS\t BLOCKS OCCUPIED");
		printf("\n     %s\t\t\t%d\t\t",ft[i].name,ft[i].nob);
		temp=ft[i].sb;
		for(j=0;j<ft[i].nob;j++)
		{
			printf("%d -> ",temp->bno);
			temp = temp->next;
		}
		printf("\n");
	}
}

