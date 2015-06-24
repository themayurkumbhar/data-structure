//programe to create two doubly linked list ,merge them & sort
#include<stdio.h>
struct dlist
{
	struct dlist *prev;
	int data;
	struct dlist *next;
}*st1=NULL,*ed1=NULL,*st2=NULL,*ed2=NULL,*st3=NULL;

//fn to create node for doubly linked list

struct dlist *createnode(int d)
{
	struct dlist *p;
	p=(struct dlist *)malloc(sizeof(struct dlist));
	p->next=p->prev=NULL;
	p->data=d;
	return p;
}

//fn to add new node at end

void addE(int d,int flg)
{
	struct dlist *p=createnode(d);
	if(flg==1)
	{
		if(st1==NULL)
			st1=p;
		else
		{
			p->prev=ed1;
			ed1->next=p;
		}
		ed1=p;
	}
	if(flg==2)
	{
		if(st2==NULL)
			st2=p;
		else
		{
			p->prev=ed2;
			ed2->next=p;
		}
		ed2=p;
	}
	return;
}

//fn to add node at the begin of doubly linked list

void addB(int d,int flg)
{
	struct dlist *p=createnode(d);
	if(flg==1)
	{
		if(ed1==NULL)
			ed1=p;
		else
		{
			p->next=st1;
			st1->prev=p;
		}
		st1=p;
	}
	if(flg==2)
	{
		if(ed2==NULL)
			ed2=p;
		else
		{
			p->next=st2;
			st2->prev=p;
		}
		st2=p;
	}
	return;
}

//display list

void display(int flg)
{
	struct dlist *p;
	if(flg==1)
	{
		p=st1;
		if(st1==NULL)
		{
			printf("\nEmpty list\n");
			getch();
			return;
		}
		while(p!=NULL)
		{
			printf("%4d",p->data);
			p=p->next;
		}

	}
	if(flg==2)
	{
		p=st2;
		if(st2==NULL)
		{
			printf("\nEmpty list\n");
			getch();
			return;
		}
		while(p!=NULL)
		{
			printf("%4d",p->data);
			p=p->next;
		}

	}
	if(flg==3)
	{
		st3=st1;
		p=st3;
		if(st3==NULL)
		{
			printf("\nEmpty list\n");
			getch();
			return;
		}
		while(p!=NULL)
		{
			printf("%4d",p->data);
			p=p->next;
		}

	}
	getch();
	return;
}

//fn to sort list

void sort(int flg)
{
	struct dlist *p,*q,*r;
	int tmp;
	if(flg==1)
	{
		if(st1==NULL)
			return;
		p=st1;
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
	}
	if(flg==2)
	{
		if(st2==NULL)
			return;
		p=st2;
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
	}
	if(flg==3)
	{
		st3=st1;
		if(st3==NULL)
			return;
		p=st3;
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
	}
	return;
}

void main()
{
	int opt,opt1,d;
	clrscr();
	while(1)
	{
		clrscr();
		printf("\nMENU\n");
		printf("1:Perform operation on 1st doubly linked list");
		printf("\n2:Perform operation on 2nd doubly linked list");
		printf("\n3:Merge two list and sort\n4:Exit\nYour option:\n");
		scanf("%d",&opt);
		if(opt>=4)
		{
			getch();
			return;
		}
		while(1)
		{
			switch(opt)
			{
				case 1:
					clrscr();
					printf("\nMENU\n");
					printf("1:Add at begin\n2:Add at end\n3:sort\n4:Display\n5:Exit");
					printf("\nyour option:\n");
					scanf("%d",&opt1);
					if(opt1>=5)
						 break;
					switch(opt)
					{
						case 1:
							printf("\nEnter data\n");
							scanf("%d",&d);
							addB(d,1);
							break;
						case 2:
							printf("\nEnter data\n");
							scanf("%d",&d);
							addE(d,1);
							break;
						case 3:
							sort(1);
							break;

						case 4:
							clrscr();
							printf("\nThe elements in the 1st list are:\n");
							display(1);
							break;
					}
					break;

				case 2:
					clrscr();
					printf("\nMENU\n");
					printf("1:Add at begin\n2:Add at end\n3:sort\n4:Display\n5:Exit");
					printf("\nyour option:\n");
					scanf("%d",&opt1);
					if(opt1>=5)
						break;
					switch(opt)
					{
						case 1:
							printf("\nEnter data\n");
							scanf("%d",&d);
							addB(d,2);
							break;
						case 2:
							printf("\nEnter data\n");
							scanf("%d",&d);
							addE(d,2);
							break;
						case 3:
							sort(2);
							break;
						case 4:
							clrscr();
							printf("\nThe elements in the 2nd list are:\n");
							display(2);
							break;
					}
					break;
				case 3:
					ed1->next=st2;
					st1->prev=ed1;
					sort(3);
					printf("\nAfter sorting\n");
					display(3);
					break;
			}
			getch();
		}
	}
	getch();
	return;
}




