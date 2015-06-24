#include<stdio.h>
#include<conio.h>

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct emp
{
   char fname[20];
	char nm[20];
	char sub_taken[20];
	char last_edu[20];
	char join_date[20];
	int sno;
	int age;
	char password[32];
       long  int bs;
	int flg;


}rec;

	FILE *fa,*ft;

	//search roll no
	int search(int no)
	{
		long int rpos=0;
		int flg=0;
		rewind(fa);
		while(1)
	{
	fread(&rec,sizeof(rec),1,fa);
	if(feof(fa))
		break;
	if(rec.sno==no)


	{
		flg=1;
		break;
	}
	rpos=ftell(fa);
	}
	if(flg==0)
	return -1;
	else
	return rpos;
}
// fn to update student record

void setdata(int no)
	{
		cleardevice();
		clrscr();
		rec.sno=no;
	printf("\n name of faculty is:");
	scanf("%s",&rec.nm);
	printf("\n Age:");
	scanf("%d",&rec.age);

	printf("\n last education:");
	flushall();
	scanf("%s",&rec.last_edu);



	flushall();
	printf("\n Basic Salary:");
	scanf("%ld",&rec.bs);
	/*
	flushall();
       printf("\n enter birth date");
	scanf("%s",&rec.birthdt);        */
	rec.flg=1;
	}







//fn to add new student record
	void newrec()
{
		int no,res;
				cleardevice();
		clrscr();
	printf("\n Sno:");
	scanf("%d",&no);
	res=search(no);
		if(res!=-1)
		{
			printf("\n Record exists");
			getch();
			return;
		}
	setdata(no);
	fwrite(&rec,sizeof(rec),1,fa);
}
	void modrec()
{
	long int pos;
	int no,opa;
	cleardevice();
			cleardevice();
		clrscr();
printf("\n record modification");
printf("\n Sno:");
scanf("%d",&no);
pos=search(no);
if(pos==-1||rec.flg==0)
{
printf("\n no such record");
	getch();
	return;
}
printf("\n old record:\n record sno :%d\nfaculty name:%s\nAge:%d\n last education:%s\nbasic salary:%ld",rec.sno,rec.nm,rec.age,rec.last_edu,rec.bs);
printf("\n1.name\n2.age\n3.education\n4.basic salary");
scanf("%d",&opa);
switch(opa)
{
	case 1:
	{
	printf("\n new faculty name:");
	scanf("%s",&rec.nm);
	break;
	}
	case 2:
	{
	printf("\n new age");
	scanf("%d",&rec.age);
	break;
	}
	case 3:
	printf("\n last education");
	scanf("%s",rec.last_edu);

	break;
	case 4:
	printf("\n basic salary");
	scanf("%d",rec.bs);
	break;
0	}
fseek(fa,pos,SEEK_SET);
fwrite(&rec,sizeof(rec),1,fa);


}

void centre(int y,char string[])
{
	int x=(80-strlen(string)+1)/2;
	gotoxy(x,y);
	printf("%s",string);
}

void delrec()
{
	int no;
	char another;
		another='Y';
	while(another=='Y'|| another=='y')
	{
	printf(" Enter the id of the employee to be deleted : ");
	scanf("%d",&no);
	ft=fopen("temp.dat","wb");
	rewind(fa);
	while(fread(&rec,sizeof(rec),1,fa)==1)
	{
		      //	if(strcmp(rec.sno,no)!=0)
		      if(rec.sno==no);
		      else
			fwrite(&rec,sizeof(rec),1,ft);
	}
	fclose(fa);
	fclose(ft);
	remove("ress.dat");
	rename("temp.dat","ress.dat");
	fa=fopen("ress.dat","r+b");
		printf("Delete another Record(Y/N): ");
		fflush(stdin);
		another=getchar();
 }
 }
      void display()
{     //     int f=0,m=0,tot=0;
	cleardevice();
		   // setcolor(9);
	centre(21,"WALCHAND COLLEGE OF ENGINEERING ");
	       centre(22,"SANGLI");
	       centre(23,"STAFF RECORD MANAGEMENT\n");
	printf("SNO NO: \t NAME: \t\t AGE :\t LAST EDUCATION : \t  BASIC SALARY:");
	  rewind(fa);
	while(1)
	{
		fread(&rec,sizeof(rec),1,fa);
	       //	 fclose(fa);
		if(feof(fa))
			break;
	       setbkcolor(14);






		printf("\n%4d \t\t %-15s  %4d  \t%-15s \t   %4ld  ",rec.sno,rec.nm,rec.age,rec.last_edu,rec.bs);
	}
	     //	printf("\nfemale:%4d male:%4d",f,m);

//		printf("\n total student:%4d",tot);

	getch();
	return;
}




 void menu()
 {
 int opt,style,size=2,x,y;
 while(1)
 {
 cleardevice();

	 style = TRIPLEX_FONT;
/* select the text style */

settextstyle(style, HORIZ_DIR, size);

// outtext("student record project");
 outtextxy(200,200," 1.new record");
   setcolor(4);


 outtextxy(220,220,"\n 2.modification in record");
   setcolor(5);

 outtextxy(240,240,"\n 3.delete record");
   setcolor(6);

 outtextxy(260,260,"\n 4.display");
 setcolor(7);

 outtextxy(280,280,"\n 8.exit");
 setcolor(8);

 outtextxy(300,300,"\n option ");
 setcolor(9);
 scanf("%d",&opt);
 if(opt>7||opt<0)
 break;
 else

	switch(opt)
 {
	case 1:
	newrec();
	break;
	case 2:
	modrec();
	break;
	case 4:
	display();
	break;
	case 3:
	delrec();
	break;
 }
 getch();
}
	}
      /*	void main()
{
	fa=fopen("rec.dat","r+b");
	if(fa==NULL)
	{     */