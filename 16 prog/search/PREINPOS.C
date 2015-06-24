#include<stdio.h>
struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
}*rt=NULL;
struct tree *createnode(int d)
{
	struct tree *p;
	p=(struct tree *)malloc(sizeof(struct tree));
	p->data=d;
	p->left=p->right=NULL;
	return p;
}
void insert (int d)
{
	struct tree *p=NULL;
	if(rt==NULL)
	{
		rt=createnode(d);
		return;
	}
	p=rt;
	while(1)
	{
		if(d<p->data)
		{
			if(p->left==NULL)
			{
				p->left=createnode(d);
				break;
			}
			p=p->left;
		}
		else
		{
			if(p->right==NULL)
			{
				p->right=createnode(d);
				break;
			}
			p=p->right;
		}
	}
	return;
}

void inorder(struct tree *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%4d",p->data);
		inorder(p->right);
	}
	else
		return;
}
void preorder(struct tree *p)
{
	if(p!=NULL)
	{
		printf("%4d",p->data);
		preorder(p->left);
		preorder(p->right);
	}
	else
		return;
}
void postorder(struct tree *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%4d",p->data);
	}
	else
		return;
}

int menu()
{
	int opt;
	clrscr();
	printf("\n**Binary search tree**\n");
	printf("\n1.Insert data\n2.Inorder R\n3.Preorder R\n4.Postorder R");
	printf("\nYour option:\n");
	scanf("%d",&opt);
	return opt;
}

void main()
{
	int opt,d;
	while(1)
	{
		opt=menu();
		switch(opt)
		{
			case 1:
				printf("\nEnter data\n");
				scanf("%d",&d);
				insert(d);
				break;
			case 2:
				printf("\nInorder\n");
				inorder(rt);
				break;
			case 3:
				printf("\nPreorder\n");
				preorder(rt);
				break;
			case 4:
				printf("\nPostorder");
				postorder(rt);
				break;
			case 5:

				getch();
				return;
		}
		getch();
	}
}






