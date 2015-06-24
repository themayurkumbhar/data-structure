#define M 100
void main()
{	int i,j,m,n,a[M][M],min,max,r,k,b[10];
	clrscr();
	printf("\nEnter rows and columns of matrix:\n");
	scanf("%d %d",&m,&n);
	clrscr();
	printf("Enter %d elements of matrix\n",m*n);
	for(i=0;i<m;i++)

	{

		for(j=0;j<n;j++)

			scanf("%d",&a[i][j]);

	}

	clrscr();
	printf("\nThe elements of matrix are:\n");

	for(i=0;i<m;i++)

	{

		for(j=0;j<n;j++)

		{

			printf("%4d",a[i][j]);

		}

		printf("\n");

	}
	for(i=0;i<m;i++)
	{
		min=a[i][0];
		for(j=0;j<n;j++)
		{
			if(a[i][j]<min)
				min=a[i][j];
		}
		for(k=0,j=0;j<n;j++)

		{

			if(a[i][j]==min)

				b[k++]=j;

		}


		while(k>=0)

		{

				max=a[i][b[k-1]];

				for(r=0;r<m;r++)

				{

					if(a[r][b[k-1]]>=max)

					{

						max=a[r][b[k-1]];

					}

				}

				if(min==max)

					printf("\nSaddle point in the matrix is:%d\nAt the position:%d %d",max,i,b[k-1]);

				k--;
		}

	}
	getch();
	return;

}
