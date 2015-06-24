void main()
{
	int gcd(int ,int);
	int a,b;
	clrscr();
	printf("\nEnter the two no's\n");
	scanf("%d %d",&a,&b);
	printf("\nGCD of two no's is %d",gcd(a,b));
	getch();
	return;
}
int gcd(int c,int d)
{
	if(c==0)
		return d;
	if(d==0)
		return c;
	else
		return gcd(d,c%d);
}
