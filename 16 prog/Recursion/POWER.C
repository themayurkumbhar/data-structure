int power(int x,int y)
{
	if(y==1)
		return x;
	else
		return(x*power(x,y-1));
}

void main()
{
	int x,y,ans;
	clrscr();
	printf("Enter base\n");
	scanf("%d",&x);
	printf("Enter power\n");
	scanf("%d",&y);
	ans=power(x,y);
	printf("%d^%d is %d",x,y,ans);
	getch();
	return;
}
