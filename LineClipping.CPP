#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
static int xmin=150,xmax=350,ymin=150,ymax=350;
static int top=1,bottom=2,left=4,right=8;
 void draw_window()
  {
   line(xmin,ymin,xmax,ymin);
   line(xmax,ymin,xmax,ymax);
   line(xmax,ymax,xmin,ymax);
   line(xmin,ymax,xmin,ymin);
  }
 int getcode(int x,int y)
  {
   int code=0;
   if(x<xmin) code |=left;
   if(x>xmax) code |=right;
   if(y>ymax) code |=top;
   if(y<ymin) code |=bottom;
   return code;
  }
 void main()
  {
   clrscr();
   int gd=DETECT,gm;
   int x1,x2,y1,y2;
   float m;
   cout<<"Enter X1 & Y1:\t";
   cin>>x1>>y1;
   cout<<"Enter X2 & Y2:\t";
   cin>>x2>>y2;
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   draw_window();
   line(x1,y1,x2,y2);
   getch();
   int outcode1=getcode(x1,y1);
   int outcode2=getcode(x2,y2);
   int accept=0;
   while(accept!=1)
    {
     m=(float)(y2-y1)/(x2-x1);
     if(outcode1==0 && outcode2==0)
      {
       accept=1;
       break;
      }
     else if ((outcode1&outcode2)!=0)
      {
       break;
      }
     else
      {
       int x,y,temp;
       if(outcode1==0)
	{
	 temp=outcode2;
	}
       else{
	 temp=outcode1;
	}
       if(temp&top)
	{
	 x=(int)(x1+(ymax-y1)/m);
	 y=ymax;
	}
       else if(temp&bottom)
	{
	 x=(int)(x1+(ymin-y1)/m);
	 y=ymin;
	}
       else if(temp&left)
	{
	 y=(int)(y1+(xmin-x1)*m);
	 x=xmin;
	}
       else if(temp&right)
	{
	 y-(int)(y1+(xmax-x1)*m);
	 x=xmax;
	}
       if(temp==outcode1)
	{
	 x1=x;
	 y1=y;
	 outcode1=getcode(x1,y1);
	}
       else
	{
	 x2=x;
	 y2=y;
	 outcode2=getcode(x2,y2);
	}
      }
    }
   if(accept==1)
    {
     setcolor(RED);
     line(x1,y1,x2,y2);
    }
   getch();
   closegraph();
   getch();
 }
