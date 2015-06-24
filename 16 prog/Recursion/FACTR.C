int fact(int n)
{
	if(n==0)
		return 1;
	else
		return(n*fact(n-1));
}
void main()
{
	int no,ans=0;
	clrscr();
	printf("\nEnter no:\n");
	scanf("%d",&no);
	ans=fact(no);
	printf("factorial of %d is %d",no,ans);
	getch();
	return;
}
