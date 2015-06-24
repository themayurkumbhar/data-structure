/////////////////////////////SINGLY LINKED LIST///////////////////////////////
#include<stdio.h>
//Menu function

int menu()
{
	int opt;
	clrscr();
	printf("\nSINGLY LINKED LIST\n");
	printf("MENU\n1:Add new node at begin\n2:Add new node at end\n");
	printf("3:Sort the list\n4:Delete first node\n5:Delete last node\n");
	printf("6:Display\n7:Delete any node\n8:reverse\n9:Exit\nYour option:\n");
	scanf("%d",&opt);
	return opt;
}


//Declaration of list


struct list
{
	int data;
	struct list *next;
}*st=NULL;

//Fn to create new node

struct list *createnode(int d)
{
	struct list *p;
	p=(struct list *)malloc(sizeof(struct list));
	p->data=d;
	p->next=NULL;
	return p;
}

//Fn to get last node address

struct list *getlnode()
{
	struct list *p=st;
	if(st==NULL)
	{
		printf("\nList is empty\n");
		return st;
	}
	while(p->next!=NULL)
		p=p->next;
	return p;
}


//Fn to display data from the list

void display()
{
	struct list *p=st;
	if(st==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;
	}
	getch();
	return;
}

//Fn to add new node at end

void adde(int d)
{
	struct list *p,*q;
	p=createnode(d);
	if(st==NULL)
		st=p;
	else
	{
		q=getlnode();
		q->next=p;
	}
	getch();
	return;
}

//Fn to add new node at the begin

void addb(int d)
{
	struct list *p;
	p=createnode(d);
	if(st==NULL)
	{
		st=p;
		return;
	}
	else
	{
		p->next=st;
		st=p;
	}
}

//fn to sort list in ascending order


void ssort()
{
	struct list *p,*q,*r;
	int tmp;
	if(st==NULL)
	{
		printf("\nList is empty so can't be sorted\n");
		return;
	}
	p=st;
	while(p->next!=NULL)
	{
		q=p;
		for(r=q->next;r!=NULL;r=r->next)
		{
			if(r->data<q->data)
				q=r;
		}
		if(p!=q)
		{
			tmp=p->data;
			p->data=q->data;
			q->data=tmp;
		}
		p=p->next;
	}
	getch();
	return;
}

//fn to delete first node from the list

void delfirst()
{
	struct list *p=st;
	if(st==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	st=st->next;
	free(p);
	return;
}

//fn to delete last node from the list

void dellast()
{
	struct list  *p=st,*q;
	if(st==NULL)
	{
		printf("\nList is Empty\n");
	}
	if(p->next==NULL)
		st=NULL;
	else
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
	}
	free(p);
}
//fn to search node
struct list *search(int v)
{
	struct list *p=st;
	while(p!=NULL)
	{
		if(p->data==v)
			break;
		p=p->next;
	}
	return p;
}

//fn to delete any node
void delvnode(int val)
{
	struct list *p=st,*q;
	if(st==NULL)
	{
		printf("\nEmpty list\n");
		getch();
		return;
	}
	q=search(val);
	if(q==NULL)
	{
		printf("\nNo such record exist\n");
		getch();
		return;
	}
	while(p->next!=q)
		p=p->next;
	p->next=q->next;
	free(q);
}

//fn to display reverse list
void reverse()
{
	struct list *p=st,*q=NULL,*r;
	while(p!=NULL)
	{
		r=p->next;
		p->next=q;
		q=p;
		p=r;
	}
	st=q;
	return;
}
void main()
{
	int d,option;
	while(1)
	{
		option=menu();
		if(option<1||option>9)
		{
			printf("\nInvalid option\n");
			getch();
			continue;
		}
		switch(option)
		{
			case 1:
				printf("\nEnter the data\n");
				scanf("%d",&d);
				addb(d);
				break;
			case 2:
				printf("\nEnter the data\n");
				scanf("%d",&d);
				adde(d);
				break;
			case 3:
				ssort();
				break;
			case 4:
				delfirst();
				break;
			case 5:
				dellast();
				break;
			case 6:
				display();
				break;
			case 7:
				printf("\nEnter val to be deleted\n");
				scanf("%d",&d);
				delvnode(d);
				break;
			case 8:
				reverse();
				break;
			case 9:
				getch();
				return;
		}
	}
}









