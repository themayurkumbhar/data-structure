
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<c:\tc\tc\bin\staff2.c>
#include<c:\tc\tc\bin\logic.c>
#include<c:\tc\tc\bin\jump.c>

     void main()

{
  char str1[10]="vikas",str2[20],ch,j=0,op,choice,another;

	int gd,gm,d,res;

	detectgraph(&gd,&gm);
	initgraph(
	&gd,&gm," ");
	man();
	cleardevice();
	flushall();
	 setbkcolor(2);


	getch();
	flushall();
	printf("\n Enter valid password:");

	while(1)
	{
		ch=getch();
	       if(ch==13)
		break;
		str2[j]=ch;
		j++;

	 }
	 str2[j]='\0';
	    another='Y';
	while(another=='Y'|| another=='y')
       {
	cleardevice();
	 printf("\n PRESS TYPE OF RECORD \n [A]STAFF RECORD\n[B]STUDENT RECORD\n");
	scanf("%c",&op);

	if(strcmp(str1,str2)==0 && op=='A')




		{
		fa=fopen("ress.dat","r+b");

		if(fa==NULL)
		{
		fa=fopen("ress.dat","wb");
		fclose(fa);
		fa=fopen("ress.dat","r+b");
		}

		menu();


		}

	      /*	else
		printf("\n invalid password");
		printf("\n re-enter password");
		*/

	      else



	if(strcmp(str1,str2)==0 && op=='B')
{        /*cleardevice();
	 do{

     clrscr();
     cleardevice();
     twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     //setbkcolor(6);
     center(7,"MAIN MENU");
     printxy(30,9,"Press:");
//     setcolor(3);
     printxy(30,11,"[A]-Create File");
     printxy(30,12,"[B]-Add Record");
     printxy(30,13,"[C]-List Record");
     printxy(30,14,"[D]-Quit Program");

     printxy(30,16,"Enter your choice...");
     gotoxy(50,16);
     choice=getch();
     choice=toupper(choice);
       switch(choice){
	  case 'A': Create(); break;
	  case 'B': Add(); break;
	  case 'C': List(); break;
	  case 'D': Quit(); break;
	  default: Err_mess(); break;
       }



   }while(choice!='D');*/
   ma();



	}

		printf("ADD ANOTHER RECORD(Y/N): ");
		flushall();
		fflush(stdin);
		another=getchar();
		fclose(fa);
		}

}
