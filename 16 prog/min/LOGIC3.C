#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct stu
{
	int rno;
	char nm[13];
	int flg;
	char address[45];
	char sx;
	char phno[15];
	char snm;
	char mi;
      //	char birthdt[20];



}rec;

	FILE *fa;
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
	if(rec.rno==no)


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
		rec.rno=no;
	printf("\n name of student is:");
	scanf("%s",&rec.nm);
	printf("\n address of student");
	scanf("%s",&rec.address);

	printf("\n sex of student");
	flushall();
	scanf("%c",&rec.sx);



	flushall();
	printf("\n enter phone number");
	scanf("%s",rec.phno);
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
	printf("\n Rno:");
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
	int no;
	clrscr();
printf("\n record modification");
printf("\n roll no:");
scanf("%d",&no);
pos=search(no);
if(pos==-1||rec.flg==0)
{
printf("\n no such record");
	getch();
	return;
}
printf("\n old record:\n record roll no:%d\nstudent name:%s\nstudent address:%s\n sex:%c\nphone number:%s",rec.rno,rec.nm,rec.address,rec.sx,rec.phno);
printf("\n new student name:");
scanf("%s",&rec.nm);
fseek(fa,pos,SEEK_SET);
fwrite(&rec,sizeof(rec),1,fa);


}

void delrec()
{
	long int pos;
	int no;
	clrscr();
	printf("\n student record deletion/n enter rno :");
	scanf("%d",&no);
	pos=search(no);
	if(pos==-1||rec.flg==0)
	{
		printf("\n no such student record exists");
		getch();
		return;
	}
	printf("\n old record :\n roll no:%d\n name:%s\n address:%s\n sex:%c\n phone number:%s",rec.rno,rec.nm,rec.address,rec.sx,rec.phno);
	rec.flg=0;
	fseek(fa,pos,SEEK_SET);
	fwrite(&rec,sizeof(rec),1,fa);
	}
	void Add(void){
   char opt;
   fa=fopen("acc.dat","ab");

   clrscr();
   Temp1();
   gotoxy(19,8);  scanf(" "); gets(rec.rno);
   gotoxy(19,10); scanf(" "); gets(rec.nm);
   gotoxy(19,12); scanf(" "); gets(rec.snm);
   gotoxy(19,14); rec.mi=getche();    rec.mi=toupper(record.mi);
   gotoxy(19,16); rec.ccode=getche();
rec.ccode=toupper(rec.ccode);
   gotoxy(5,22); clreol(); printxy(79,22,"º");
   fprintf(fp,"%s %s %s %c%c",rec.snum,rec.fname,rec.sname,rec.mi,rec.ccode);
   gotoxy(5,21); clreol(); center(21,"Record successfully added!");
printxy(79,21,"º");  gotoxy(53,22); delay(1000);
   center(22,"Press any key to go to main menu..."); getch();
   fclose(fa);
}
      void display()
{          int f=0,m=0,tot=0;
	cleardevice();
	rewind(fa);
		printf("ROLL NO: \t NAME: \t\t ADDRESS :\t \tSEX: \t  PHONE NO:");
	while(1)
	{
		fread(&rec,sizeof(rec),1,fa);
	       //	 fclose(fa);
		if(feof(fa))
			break;
	       setbkcolor(12);
	       setcolor(10);

	      if(rec.sx=="F"||rec.sx=="f")
		  f++;
		  else

		  m++;
		  tot=f+m;
		  /*
	       outtextxy(22,52,"ROLL NO:");
		outtextxy(71,52,"NAME:");
		 outtextxy(82,102,"ADDRESS:");
		  outtextxy(93,11,"SEX:");
		  outtextxy(123,11,"PHONE NO:");
		  */


		printf("\n\n%4d \t\t %-15s   %-15s  \t %c  %15s  ",rec.rno,rec.nm,rec.address,rec.sx,rec.phno);
	}
		printf("\nfemale:%4d male:%4d",f,m);

		printf("\n total student:%4d",tot);

	getch();
	return;
}
/*
void count()
{
		if(rec.sx=="F")
		  f++;
		  if(rec.sx=="M")
		  m++;
		printf("\n\n%4d  %-15s   %-15s   %c  %15s",rec.rno,rec.nm,rec.address,rec.sx,rec.phno);
		printf("\nfemale:%4d male:%4d",f,m);
		tot =f+m;
		printf("\n total student:",tot);
} */
 drawline()
{
	int i;


	for(i=0;i<10;i++)
	{
	printf("--");
       //	i++;
	}
	return 0;
}
void heading()
{
	printf("\n student data");
	drawline();
	printf("\n %35 %45 %-155 %45 %33 %44\n","rno","name","address","phone no","sex");
	drawline();
	printf("\n");
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
	add();
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
 return;
 }
}