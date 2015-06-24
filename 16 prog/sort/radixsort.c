#define M 10
struct que
{
	int arr[M];
	int fr,rr;
}q[M];
void init()
{
	int i=0;
	while(i<M)
	{
		q[i].fr=0;
		q[i].rr=-1;
		i++;
	}
}	
void insert(int *p,int pos)
{
	int i=0,index,apos;
	init();
	while(i<10)
	{
		switch(pos)
		{
			case 1:
				index=*(p+i)%10;
				break;
			case 2:
				index=(*(p+i)/10)%10;
				break;
			case 3:
				index=*(p+i)/100;
		}
		apos=++q[index].rr;
		q[index].arr[apos]=*(p+i);
		i++;
	}
}
void remq(int *p)
{
	int i=0,j=0,index=0;
	while(i<M)
	{
		j=0;
		while(j<=q[i].rr)
		{
			*(p+index)=q[i].arr[j];
			j++;
			index++;
		}
		i++;
	}
}
int main()
{
	int i=0,x[M];
	while(i<M)
	{
		printf("\n Enter 3 Digit No:");
		scanf("%d",&x[i]);
		if(x[i]<100||x[i]>999)
		{
			printf("\n Invalid Input");
			continue;
		}
		i++;
	}
	printf("\n Before Sorting:");
	for(i=0;i<M;i++)
		printf("%4d",x[i]);
	for(i=1;i<=3;i++)
	{
		insert(x,i);
		remq(x);
	}
	printf("\n After Sorting");
	for(i=0;i<M;i++)
		printf("%4d",x[i]);
	getch();
	return;
}


	
