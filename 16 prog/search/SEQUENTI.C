void main()
{
	int a[10],i,val;
	clrscr();
	printf("\nEnter 10 no's\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\nEnter value you want to search\n");
	scanf("%d",&val);
	printf("\nThe array elements are\n");
	for(i=0;i<10;i++)
		printf("%3d",a[i]);
	for(i=0;i<10;i++)
	{
		if(a[i]==val)
		{
			printf("\nNo is found at %d position",i+1);
			break;
		}
	}
	if(i==10)
		printf("\nNot found");
	getch();
	return;
}
