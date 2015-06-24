#include<stdio.h>
#include<conio.h>
void main()
{
	FILE *fp;
	char ch;
	int a;
	fp=fopen("cap.txt","w+");
	printf("\nPress Esc to stop operation\n");
	while(1)
	{
		ch=getche();
		a=ch;
		if(a==27)
			break;
		fputc(ch,fp);
	}
	printf("\nThe characters in the file are:\n");
	rewind(fp);
	while(1)
	{
		if(feof(fp))
			break;
		ch=fgetc(fp);
		if(ch=='\n')
			printf("\n");
		else
			printf("%c",ch);
	}
	fclose(fp);
	getch();
	return;
}

	
