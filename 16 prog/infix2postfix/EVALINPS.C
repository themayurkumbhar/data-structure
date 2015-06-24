#include<conio.h>
#include<ctype.h>
#include<stdio.h>
struct stack
{
	char opr[10];
	int top;
}s;

void push(char t)
{
	s.opr[++s.top]=t;
}
void pop()
{
	--s.top;
}
int empty()
{
	if(s.top==-1)
		return 1;
	return 0;
}
int preced(char stktop,char opr)
{
	if(stktop!='('&&opr==')')
		return 1;
	else
		return 0;
}
int main()
{
	char pstr[40],opr;
	int opr1,opr2,result,i;
//	clrscr();
	s.top=-1;
	printf("\npostfix string:\n");
	scanf("%s",pstr);
	i=0;
	while(pstr[i]!='\0')
	{
		if(isdigit(pstr[i]))
			push(pstr[i]);
		else
		{
			opr2=s.opr[s.top]-48;
			pop();
			opr1=s.opr[s.top]-48;
			pop();
			opr=pstr[i];
			switch(opr)
			{
				case '+':
					result=opr1+opr2;
					break;
				case '-':
					result=opr1-opr2;
					break;
				case '*':
					result=opr1*opr2;
					break;
				case '/':
					result=opr1/opr2;
					break;
			}
			push((char)(result+48));
		}
		i++;
	}
	printf("\nresult:%d",result);
	scanf("%d",&result);
	getch();
	return 0;
}

