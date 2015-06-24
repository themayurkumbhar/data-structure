#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
struct stu
{      int tot;
      int rno;
      int recno;
//      int opt;
      char nm[30];
      int day;
      char mon;
}record;
void main()
{
      FILE *f1;
	char ch;
	int opt;
    int gdriver = DETECT, gmode, errorcode;
   int midx, midy,i,size,style,percent;
   char stylestr[67];
   int stangle , endangle, radius = 200;



   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, " ");


f1=fopen("ree.txt","a+");


while(1)
{

     {
	ch=getche();
	  if(ch=='*')
	  break;
	  else

	printf("\n enter rno:");
	scanf("%d",&record.rno);
	flushall();
	printf("\n name");
	scanf("%s",&record.nm);

	flushall();
	printf("\n enter choice of month\n1.sept\n2.oct\n3.nov");
	scanf("%d",&opt);
	switch(opt)
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
		record.tot=31;
		printf("\n nov");
		break;
		printf("%d",record.tot);
       }



	printf("\n enter no. of days present");

	scanf("%d",&record.day);

	//flushall();
	fprintf(f1,"%d %s %d %d\n",record.rno,record.nm,record.day,opt);
       //	fwrite(&record,sizeof(record),1,f1);
}

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;

   /* set fill style and draw a pie slice */



  setbkcolor(0);

    setfillstyle(SOLID_FILL,3);
     stangle=0 ,endangle,radius=100;

     printf("\n chart is:");


     endangle=(record.day*360)/record.tot;
     percent=(record.day*100)/record.tot;
     printf("present days:%d",percent);
     if(percent<75)
     {
	printf("\n defaulter");
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

   outtext("student record project");
   stangle=endangle ,endangle=360,radius=100;
   setcolor(4);
   size=1;
   settextstyle(style,HORIZ_DIR,size);
   outtextxy(222,99,"what we have to do");
     setfillstyle(SOLID_FILL, 12);
   pieslice(midx, midy, stangle, endangle, radius);
   getch();
   clrscr();
   cleardevice();
//   closegraph();

}





 getch();
}
