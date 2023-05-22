//Midpoint Circle Drawing Algorithm
#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
 void display(int xc,int yc,int X,int Y)
  {
   putpixel(xc+X,yc+Y,RED);
   putpixel(xc-X,yc+Y,RED);
   putpixel(xc+X,yc-Y,RED);
   putpixel(xc-X,yc-Y,RED);
   putpixel(xc+Y,yc+X,RED);
   putpixel(xc-Y,yc+X,RED);
   putpixel(xc+Y,yc-X,RED);
   putpixel(xc-Y,yc-X,RED);
  }
//Function to draw circle using MidPoint Algo
 void midpoint(int xc,int yc,int r)
  {
   int X=0;
   int Y=r;
   int deci=1-r;
   display(xc,yc,X,Y);
   while(X<=Y)
    {
    if(deci>0)
    {
     Y--;
     X++;
     deci=deci+2*(X-Y)+1;
    }
   else
    {
     X++;
     deci=deci+(2*X)+1;
    }
   display(xc,yc,X,Y);
  }
 }
 void main()
  {
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   cout<<" <GRAPHICS MODE> "<<endl;
   midpoint(200,200,50);
   getch();
   closegraph();
  }