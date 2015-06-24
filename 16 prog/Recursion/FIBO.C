//fibonacci via recursion
void main()
{
	int fib(int);
	int i;
	clrscr();
	printf("\nFirst ten no's of fibo are:");
	for(i=0;i<10;i++)
	{
		printf("%3d",fib(i));
	}
	getch();
	return;
}
int fib(int x)
{
	if(x==0||x==1)
		return x;
	else
		return (fib(x-1)+fib(x-2));
}

