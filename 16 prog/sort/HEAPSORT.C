#include<stdio.h>

int restoreHup(int*,int);
int restoreHdown(int*,int,int);

int main()
{
        int a[20],n,i,j,k;
        printf("Enter the number of elements to sort : ");
        scanf("%d",&n);

        printf("Enter the elements : ");
        for(i=1;i<=n;i++){
                scanf("%d",&a[i]);
                restoreHup(a,i);
        }


        j=n;
        for(i=1;i<=j;i++)
        {
                int temp;
                temp=a[1];
                a[1]=a[n];
                a[n]=temp;
                n--;
                restoreHdown(a,1,n);
        }

        n=j;

	printf("sorted:");
        for(i=1;i<=n;i++)
		printf("%4d",a[i]);
		getch();
return 0;
}



int restoreHup(int *a,int i)
{
        int v=a[i];

        while((i>1)&&(a[i/2]<v))
        {
                a[i]=a[i/2];
                i=i/2;
        }
        a[i]=v;
	return 0;
}

int restoreHdown(int *a,int i,int n)
{
        int v=a[i];
        int j=i*2;
        while(j<=n)
        {
                if((j<n)&&(a[j]<a[j+1]))
                        j++;
                if(a[j]<a[j/2]) break;

                a[j/2]=a[j];
                j=j*2;
        }
        a[j/2]=v;
	return 0;
}


