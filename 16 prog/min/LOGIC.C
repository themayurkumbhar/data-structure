
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
FILE *fp;


struct student
{
  char nm[20];
  char snum[13];
  char fname[20];
  char sname[20];
  char mi;
  char ccode;
  int rno;
  int day;
  int opt;
  int tot;


}record;

void Temp1(void);
void twolinebox(int x1,int y1,int x2,int y2)
{
 int x,y;
 gotoxy(x1,y1);
 printf("É"); //alt-201
 gotoxy(x2,y1);
 printf("»"); //alt-187
  for(y=y1+1;y<y2;y++)
  {
    gotoxy(x1,y);         //used for making left lines
    printf("º"); //alt-186
    gotoxy(x2,y);
   printf("º"); //alt-186

  }
 gotoxy(x1,y2);
 printf("È"); //alt-200
 gotoxy(x2,y2);
 printf("¼"); //alt-188
  for(x=x1+1;x<x2;x++)
  {
    gotoxy(x,y1); printf("Í"); //alt-205
    gotoxy(x,y2); printf("Í"); //alt-205
  }
 gotoxy(x1+1,y1+1);
}

void printxy(int x,int y,char string[])
{
 gotoxy(x,y);
 //setcolor(10);
 //setbkcolor(3);
 //outtext(string);
 //getch();
 printf("%s",string);
}

void center(int y,char string[])
{
	int x=(80-strlen(string)+1)/2;
	gotoxy(x,y);
	printf("%s",string);
}

void Create(void){
      //	cleardevice();
  char opt;
  cleardevice();
  center(21,"WARNING!!!");
  center(22,"You are about to create a new file");
  center(23,"This will erase all records in the file...");
  center(24,"Are you sure you want to proceed?[Y/N] ");
  opt=getche();
  opt=toupper(opt);
  if(opt=='Y')
  {
   fp=fopen("Group4.txt","w");
   center(24,"                                             ");
   center(24,"File successfully created!");
  }
   getch();
 fclose(fp);
}
void Add(void)
{
   char opt;
	cleardevice();
   fp=fopen("Group4.txt","a");

//   clrscr();
   Temp1();
   gotoxy(19,8);  scanf(" "); gets(record.snum);
   gotoxy(19,10); scanf(" "); gets(record.fname);
   gotoxy(19,12); scanf(" "); gets(record.sname);
   gotoxy(19,14); record.mi=getchar();
   //scanf("%c",&record.mi);
   getch();
   record.mi=toupper(record.mi);
   flushall();
   gotoxy(19,16);
   //scanf("%c",&record.ccode);
   record.ccode=getchar();
record.ccode=toupper(record.ccode);
	//gotoxy(19,19);
      //	scanf(" ");
       //	gets(record.sx);
    // scanf("%c",record.sx);
   gotoxy(5,22);
   //clreol();
   printxy(79,22,"º");
   fprintf(fp,"%s %s %s %c%c",record.snum,record.fname,record.sname,record.mi,record.ccode);
   gotoxy(5,21); clreol(); center(21,"Record successfully added!");
printxy(79,21,"º");  gotoxy(53,22); delay(1000);
   center(22,"Press any key to go to main menu..."); getch();
   fclose(fp);
}

void Attend()
{           int opt,opta,i=1,rno,day,op,tot;

FILE *f1;
//char t[1000];
//cleardevice();
char ch,nm;
int midx, midy,size,style,percent;
   char stylestr[67];
   int stangle , endangle, radius = 200;

f1=fopen("ree.txt","r+");
clrscr();
cleardevice();
if(f1==NULL)
{
	printf("\n file is missing");
	getch();
	return;
}
while(1)
{
printf("\n enter roll no:");
		scanf("%d",&opta);
		printf("enter month no:\n1.sept\n2.oct\n3.nov");

		scanf("%d",&op);
		switch(op)
	{
		case 1:
		record.tot=31;
		printf("\n sept");
		break;
		case 2:
		record.tot=30;
		printf("\n oct");
		break;
		case 3:
		record.tot=30;
		printf("\n nov");
		break;
	}

	while(opta!=record.rno)


  {	fscanf(f1,"%d %s %d %d",&record.rno,record.nm,&record.day,&opt);


     //	if(feof(f1))
       //	break;
       if(opta==record.rno && op==opt)
	{
	printf("\n roll no:%d",record.rno);
	printf("\n Name:%s",record.nm);
	printf("\n no. of days:%d",record.day);

	}

  }
		midx = getmaxx() / 2;
	midy = getmaxy() / 2;

   /* set fill style and draw a pie slice */



  setbkcolor(0);

    setfillstyle(SOLID_FILL,3);
     stangle=0 ,endangle,radius=100;

     printf("\n\t\t\t\t\t chart is:\n");


     endangle=(record.day*360)/record.tot;
     percent=(record.day*100)/record.tot;
     printf("ATTENDANCE:%d",percent);
     if(percent<75)
     {
	outtextxy(100,15,"\n defaulter");
     }
     else
     printf("\n regular");

	   pieslice(midx, midy, stangle, endangle, radius);

	  setfillstyle(SOLID_FILL,11);
   pieslice(midx, midy, stangle, endangle, radius);
   moveto(99,12);

	 size = 2;
	 style = TRIPLEX_FONT;
/* select the text style */
settextstyle(style, HORIZ_DIR, size);

   outtextxy(300,15,"ATTENDANCE SHEET");
   stangle=endangle ,endangle=360,radius=100;
   setcolor(4);
   size=1;
   settextstyle(style,HORIZ_DIR,size);
//   outtextxy(222,99,"what we have to do");
     setfillstyle(SOLID_FILL, 12);
   pieslice(midx, midy, stangle, endangle, radius);
   getch();
    break;
   clrscr();
   cleardevice();

//   closegraph();

}

}




void Temp1(void){
  twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"ADD RECORD");
  printxy(6,8,"Student no: ");
  printxy(6,10,"First Name: ");
  printxy(6,12,"Last Name: ");
  printxy(6,14,"Middle init:");
  printxy(6,16,"Course code: ");

  center(22,"Course code: [A]-CompSci, [B]-for InfoTech, [anykey]-Sevices");
  gotoxy(19,7);
}

void List(void){
//setbkcolor(12);


int count=0,i,x=0,page=1,CS=0,IT=0,Serv=0,style=DEFAULT_FONT;
float size=2;
//setbkcolor(15);
       cleardevice();
fp=fopen("Group4.txt","r");
	//size=2;
	settextstyle(style, HORIZ_DIR, size);

	setcolor(3);
	settextstyle(style, HORIZ_DIR, size);

 outtextxy(150,10,"Walchand College Of Engg ");
  center(3,"Sangli");
 center(5,"computer science & information technology");
 //size=2;
 settextstyle(style,HORIZ_DIR, size);

 outtextxy(10,80,"Record  Student #    Name      Course " );
 for(i=1;i<80;i++)
 {
 gotoxy(i,8);
 puts("Í");
 }

 while(fscanf(fp,"%s %s %s %c %c",&record.snum,&record.fname,&record.sname,&record.mi,&record.ccode)!=EOF)
 {
    if(count!=0&&count%5==0)
    {
    printxy(5,23,"Press any key tocontinue...");
    getch();
    x=0;
	   for(i=10;i<=24;i++)
	   {
	   gotoxy(1,i);
	   clreol();
	   }
		page++;
    }

	gotoxy(70,4); printf("Page %d",page);
	gotoxy(13,10+x); printf("%d",count+1);
    gotoxy(19,10+x); printf("%s",record.snum);
    gotoxy(37,10+x); printf("%s, %s %c .",record.sname,record.fname,record.mi);
    gotoxy(62,10+x);
       switch(record.ccode)
       {
	 case 'A': printf("CompSci"); CS++; break;
	 case 'B': printf("InfoTech"); IT++; break;
	 default : printf("Services"); Serv++; break;
       }
  x++;
  count++;
 }
 printxy(25,17,"TOTAL");
 gotoxy(15,18); printf("Comp Sci: %d",CS);
 gotoxy(15,19); printf("InfoTech: %d",IT);
 gotoxy(15,20); printf("Services: %d",Serv);
 printxy(5,23,"Press any key to go to main menu...");
 getch();

 fclose(fp);
}

void Quit(void)
{
 cleardevice();
twolinebox(2,2,79,24);
 center(8,"PROGRAMMED");
 center(9,"BY");
 center(11,"Group 3");
 center(13,"Vikas");
 center(14,"Kapil");
 center(15,"Bhushan");
 delay(5000);
 exit(1);
 fclose(fp);

	     /*
	  {
		int i,j,gdriver=DETECT,gmode,errorcode;
		char msg[80];

		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		setbkcolor(14);
		j=420;

		for(i=400;i>=0;i--)
		{
			setcolor(RED);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			setcolor(RED);
			outtextxy(250,j,"DESIGNED & CODED BY");
			outtextxy(260,j+40," VIKAS P.PANCHARIYA");
			outtextxy(260,j+80," SANJAY MEHTA");
			outtextxy(230,j+120,"DEPT. OF COMPUTERICAL SCIENCE");
			outtextxy(210,j+160,"WALCHAND COLLAGE OF ENGINEERING.,SANGLI.");
			outtextxy(210,j+200,"SPECIAL THANKS FOR GUIDANCE");
			outtextxy(260,j+240,"MISS. BHANDARI");

			outtextxy(240,j+280,"ÄÄÄÄÄÄÄ THANKS ÄÄÄÄÄÄÄ");
			delay(20);
			j--;
			cleardevice();
		}
		gotoxy(60,29);
		printf("Hit any key");
		getch();
		closegraph();
		exit(0);
	   }   */
}

void Err_mess(void){
sound(1000);
center(22,"Invalid Input!");
delay(1000);
nosound();
}


   void ma()
{ char choice;
//clrscr();
//cleardevice();
 char str1[10]="vikas",str2[20],ch,j=0;
 int gd,gm,d,res;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm," ");

  cleardevice();


	/*center(22,"\n ENTER VALID PASSWORD:");

	while(1)
	{
		ch=getch();
	       if(ch==13)
		break;
		str2[j]=ch;
		j++;

	 }
	 str2[j]='\0';
	 if(strcmp(str1,str2)==0)  */



   do{
     clrscr();
     cleardevice();
     twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     setbkcolor(6);
     center(7,"MAIN MENU");
     printxy(30,9,"Press:");
//     setcolor(3);
     printxy(30,11,"[A]-Create File");
     printxy(30,12,"[B]-Add Record");
     printxy(30,13,"[C]-List Record");
     printxy(30,14,"[D]-Quit Program");
     printxy(30,15,"[E]-Attendance");
     printxy(30,18,"Enter your choice..."); gotoxy(50,16);
     choice=getch(); choice=toupper(choice);
       switch(choice){
	  case 'A': Create(); break;
	  case 'B': Add(); break;
	  case 'C': List(); break;
	  case 'D': Quit(); break;
	  case 'E':Attend();break;
	  default: Err_mess(); break;
       }


   }while(choice!='D');
}