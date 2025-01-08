#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include "BRESENHA.CPP"
void edgef(int X,int Y)
 {
	while(X<640)
	 {
	  if(getpixel(X,Y)==0)
	   {
	    putpixel(X,Y,YELLOW);
	   }
	  else if(getpixel(X,Y)!=0)
	   {
	    putpixel(X,Y,BLACK);
	   }
	  X++;
       }
 }
void edge_fill(int x1,int y1,int x2,int y2)
 {
  int dx,dy,p;
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  int x=x1;
  int y=y1;
  if(dx>=dy)
   {
    p=2*dy-dx;
    do{
     if((y2-y1)!=0)
      {
       edgef(x,y);
      }
     else;
     if(p>0)
      {
      if(y2>y1)
      {
       y++;
      }
      else
       {
	y--;
       }
       p=p+2*dy-2*dx;
      }
     else
      {
       p=p+2*dy;
      }
     if(x1<x2)
     {
      x++;
     }
     else
      {
       x--;
      }
    }while(x!=x2);
   //edgef(x,y);
   }
  else
   {
    p=2*dx-dy;
    do{
      if(y2-y1!=0)
     {
      edgef(x,y);
     }
    else;
     if(p>0)
      {
       if(x1<x2)
       {
	x++;
       }
      else
       {
	x--;
       }
       p=p+2*dx-2*dy;
      }
     else
      {
       p=p+2*dx;
      }
     if(y1<y2)
     {
     y++;
     }
    else
     {
      y--;
     }
    }while(y!=y2);
   //edgef(x,y);
   }
 }
void main()
 {
  clrscr();
  int x[6],y[6],i;
  int dy;
  float m;
  int gm,gd=DETECT;
  for(i=0;i<5;i++)
   {
    cout<<"Enter X co-ordinate:\t";
    cin>>x[i];
    cout<<"Enter Y co-ordinate:\t";
    cin>>y[i];
   }
  initgraph(&gd,&gm,"C:/TURBOC3/BGI");
  Bresenham(x[0],y[0],x[1],y[1]);
  Bresenham(x[1],y[1],x[2],y[2]);
  Bresenham(x[2],y[2],x[3],y[3]);
  Bresenham(x[3],y[3],x[4],y[4]);
  Bresenham(x[0],y[0],x[4],y[4]);
  i=0;
  x[5]=x[0];
  y[5]=y[0];
  for(i=0;i<6;i++)
   {
    edge_fill(x[i],y[i],x[i+1],y[i+1]);
   }
  getch();
  closegraph();
  getch();
 }

