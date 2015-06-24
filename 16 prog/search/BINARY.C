#define M 10
void main()
{
	int x[M],i=0,l,r,mid,sv;
	clrscr();
	while(i<M)
	{
		printf("\nNO:");
		scanf("%d",&x[i]);
		if(i>0)
		{
			if(x[i]<x[i-1])
			{
				printf("\nInvalid input\n");
				getch();
				continue;
			}
		}
		i++;
	}
	printf("\nEnter search value:");
	scanf("%d",&sv);
	l=0;
	r=M-1;
	do
	{
		mid=(l+r)/2;
		if(x[mid]==sv)
			break;
		if(sv<x[mid])
			r=mid-1;
		else
			l=mid+1;
	}while(l<=r);
	if(l>r)
		printf("Not found");
	else
		printf("Found");
	getch();
	return;
}

