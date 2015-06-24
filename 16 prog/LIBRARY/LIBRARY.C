#include<stdio.h>
struct library
{
	int bookav;
	char *booknm,*authrnm;
}b[5];

add()
{
	int i=1;
	for(;i<6;i++)
	{
		 b[i].booknm=(char *)malloc(sizeof(char));
		 b[i].authrnm=(char *)malloc(sizeof(char));
	}
	for(i=1;i<6;i++)
	{
		printf("Enter book name %d :",i);
		scanf("%s",b[i].booknm);
		printf("Enter author name %d :",i);
		scanf("%s",b[i].authrnm);
		printf("Enter no of book:");
		scanf("%d",&b[i].bookav);
	}
	return;
}

display()
{
	int j;
	printf("%5s %10s %10s %10s\n","srno", "Book name","Author name","Available");
	for(j=38;j>0;j--)
	printf("_");
	printf("\n");
	for(j=1;j<6;j++)
	printf("%5d %10s %10s %5d\n",j, b[j].booknm,b[j].authrnm,b[j].bookav);
	return;
}

withdraw()
{
	int opt,i;

	while(1)
	{
		printf("Enter sr no of book to be witndraw\n");
		scanf("%d",&opt);
		if(opt<1||opt>5)
		{
			printf("Invalid option");
			continue;
		}
		if(b[opt].bookav==0)
			printf("Books are not available:");
		else
		{
			b[opt].bookav--;
			display();
		}
		printf("Do you want to withdraw another book? yes[1]/no[0]");
		scanf("%d",&i);
		if(i==1)
			continue;
		else
			break;
	}
	return;
}

deposit()
{
	int opt,i;
	while(1)
	{
		printf("Enter sr no of book to be deposit \n");
		scanf("%d",&opt);
		if(opt<1||opt>5)
		{
			printf("Invalid option");
			continue;
		}
		b[opt].bookav++;
		display();
		printf("Do you want to deposit another book? yes[1]/no[0]");
		scanf("%d",&i);
		if(i==1)
			continue;
		else
			break;
	}
	return;
}

void main()
{
	int i;
	clrscr();
	add();
	clrscr();
	printf("\nThe no. of available books are:\n");
	display();
	printf("\n1:Withdarw \n2:Deposit\n3:Exit\nEnter your option:");
	scanf("%d",&i);
	if(i==1)
		withdraw();
	if(i==2)
		deposit();
	if(i==3)
	{
		getch();
		return;
	}
}


