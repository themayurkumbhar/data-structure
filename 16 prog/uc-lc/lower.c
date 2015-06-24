#include<stdio.h>
void main()
{
	FILE *fp,*ft;
	char ch;
	fp=fopen("cap.txt","r");
	ft=fopen("copy.txt","w");
	while(1)
	{
		if(feof(fp))
			break;
		ch=fgetc(fp);
		if(ch==27)
			break;
		if(ch>=65&&ch<=90)
		{
			ch=ch+32;
			fputc(ch,ft);
		}
		else
			fputc(ch,ft);
	}
	fclose(fp);
	fclose(ft);
	return;
}
		
