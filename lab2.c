#include<stdio.h>
#include<stdlib.h>
void  main()
	{
	FILE *fptr1,*fptr2;
	char c,source[100],dest[100];

	printf("Enter the source filename:");
	scanf("%s",source);

	fptr1=fopen(source,"r");

	if(fptr1==NULL)
	{
	printf("Cant't open the file\n");
	exit(0);
	}

	printf("Enter the destination  filename:");
        scanf("%s",dest);

	fptr2=fopen(dest,"w");

        if(fptr2==NULL)
        {
        printf("Cant't open the file\n");
        exit(0);
	}

	//c=fgetc(fptr1);
	while((c=fgetc(fptr1))!=EOF)
	{
	fputc(c,fptr2);
	}


	printf("File successfully copied  to %s\n",dest);
/*	while((c=fgetc(fptr2))!=EOF)
        {
        printf(c);
        }*/

	fclose(fptr2);

	fptr2=fopen(dest,"r");
	c=fgetc(fptr2);
	while(c!=EOF)
        {
	printf("%c",c);
	c=fgetc(fptr2);
        }
	printf("\n");




	fclose(fptr1);
	fclose(fptr2);

	//return 0;
}

