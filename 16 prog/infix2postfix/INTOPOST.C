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
void main()
{
	char istr[30],pstr[30],opr;
	int i,j;
	clrscr();
	s.top=-1;
	printf("Enter infix string:\n");
	scanf("%s",istr);
	i=0;
	j=0;
	while(istr[i]!='\0')
	{
		if(isalpha(istr[i]))
			pstr[j++]=istr[i];
		else
		{
			while(!empty()&&preced(s.opr[s.top],istr[i]))
			{
				pstr[j++]=s.opr[s.top];
				pop();
			}
			if(empty()||istr[i]!=')')
				push(istr[i]);
			else
			{
				opr=s.opr[s.top];
				while(opr!='(')
				{
					pstr[j++]=s.opr[s.top];
					pop();
					opr=s.opr[s.top];
				}
				pop();
			}
		}
		i++;
	}
	while(!empty())
	{
		pstr[j++]=s.opr[s.top];
		pop();
	}
	pstr[j]='\0' ;
	puts(pstr);
	getch();
	return;
}
