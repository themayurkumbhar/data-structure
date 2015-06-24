//Code :
# include <graphics.h>
# include <stdlib.h>
# include <conio.h>
# include <dos.h>

int x,y,maxx,maxy,i,j;

int main(void)
{
	int gdriver = DETECT, gmode,midx,midy,style;
	void *image;
	unsigned int size;
	char ch;
	void fillBox(int,int);
	int Row,Col;

	// Initialize graphics drivers and mode.
	initgraph(&gdriver,&gmode,"d:\tc\bgi ");

	// Draw a rectangle
	// rectangle(x1,y1,x2,y2)
	maxx=getmaxx(); // x2
	maxy=getmaxy(); // y2
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	rectangle(10,10,maxx-10,maxy-10);

	// Puts Pixel in the Rectangle.
	fillBox(maxx,maxy);
       x=y=100;
	// Draw Circle and FillColor
	setfillstyle(1,14);
	circle(x,y,20);
	floodfill(x,y,15);

	// Creating the Image
	size = imagesize(x,y,x+20,y+20);
	image=malloc(size);
	getimage(x-20,y-20,x+20,y+20,image);
	x-=20;
	y-=20;
		moveto(midx,midy);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	 size = 3;
	 style = TRIPLEX_FONT;
/* select the text style */
settextstyle(style, HORIZ_DIR, size);

outtextxy(300,300,"student and staff record management");
/*setfillstyle(1,11);
setcolor(12);
for(i=1;i<14;i++)
{
	setcolor(i);
						    );
      outtext("WELCOME");
	}
	outtextxy(200,100,"welcome");   */
	// Will Displays till Any key is hit !!!...
			while(!kbhit())
			{

			       //	Row = x; Col = y;
				putimage(x,y,image,XOR_PUT);    // clears the Image from Screen
				//x=random(maxx-70);
				//y=random(maxy-70);
				//fillBox(maxx,maxy);
				x=x+10;
			  /* if(x<50)
					x=50;
					if(y<50)
						y=50; */
					putimage(x,y,image,OR_PUT); // Puts the image on screen.
					delay(50); // Waits for few Seconds.
					if(x>555)
					{
						putimage(x,y,image,XOR_PUT);
						Row = x; Col = y;
						for(i=0;i<540;i++)

						{
							x=random(maxx-10);
							y=random(maxy-10);
							if(x>10 && y>10)
						       putpixel(x,y,14);
						}
						for(i=1;i<14;i++)
{          settextstyle(style, HORIZ_DIR, size);
	size=9;
	setcolor(i);

      outtext("WELCOME");
	}
						//putpixel(x,y,14);
						x= Row;
						y=Col;
						x=10;
						y=y+20;
						putimage(x,y,image,XOR_PUT);
					}
					if(y>433)
					{
					     /*	putimage(x,y,image,XOR_PUT);
						Row = x; Col = y;
						fillBox(maxx,maxy);
						x= Row;
						y=Col;                  */
						for(i=1;i<14;i++)
{
	setcolor(i);

      outtext("WELCOME");
	}
					       /*	x=10;
						y=30;
						putimage(x,y,image,XOR_PUT);   */
					}
			}
	free(image); //Removes the image from the Screen.
	closegraph(); // Closes the Graphics Mode.
}

void fillBox(int maxx,int maxy)
{
	cleardevice();   // Clears the Graphics Screen
	maxx=getmaxx(); // x2
	maxy=getmaxy(); // y2
	rectangle(10,10,maxx-10,maxy-10);
	for(i=0;i<8000;i++)
	{
		x=random(maxx-10);
		y=random(maxy-10);
		if(x>10 && y>10)
			putpixel(x,y,14);
	}
}
