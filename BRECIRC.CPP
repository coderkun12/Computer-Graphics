//BRESENHAM CIRCLE DRAWING ALGORITHM
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
void display(int xc,int yc,int X,int Y);
void brcircle(int xc,int yc,int r)
 {
  int X=0;
  int Y=r;
  display(xc,yc,X,Y);
  int p=3-2*r;
  do{
   if(p>0)
    {
     Y--;
     X++;
     p=p+4*(X-Y)+10;
    }
   else
    {
     X++;
     p=p+4*X+6;
    }
   display(xc,yc,X,Y);
  }while(X<=Y);
 }
 void display(int xc,int yc,int X,int Y)
 {
  putpixel(xc+X,yc+Y,RED);
  putpixel(xc-X,yc+Y,BLUE);
  putpixel(xc+X,yc-Y,YELLOW);
  putpixel(xc-X,yc-Y,GREEN);
  putpixel(xc+Y,yc+X,BLACK);
  putpixel(xc-Y,yc+X,BROWN);
  putpixel(xc+Y,yc-X,CYAN);
  putpixel(xc-Y,yc-X,WHITE);
 }

  void main()
   {
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:/TURBOC3/BGI");
    brcircle(250,250,40);
    getch();
    closegraph();
    getch();
   }