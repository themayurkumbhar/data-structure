int sum(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return(n+sum(n-1));
}
void main()
{
	int no,ans;
	clrscr();
	printf("\nEnter the no's you want to add\n");
	scanf("%d",&no);
	ans=sum(no);
	printf("\nThe sum of 1st %d no's is %d",no,ans);
	getch();
	return;
}