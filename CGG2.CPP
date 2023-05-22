//Write a code to implement:
//1. Mid Point Circle Drawing algorithm.
//2. Bresenham Circle Drawing algorithm.
//3. Create a Object using the algorithms.

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>

//Function to put pixels.
 void display(int xc,int yc,int X,int Y)
 {
  putpixel(xc+X,yc+Y,BROWN);
  putpixel(xc-X,yc+Y,BROWN);
  putpixel(xc+X,yc-Y,BROWN);
  putpixel(xc-X,yc-Y,BROWN);
  putpixel(xc+Y,yc+X,BROWN);
  putpixel(xc-Y,yc+X,BROWN);
  putpixel(xc+Y,yc-X,BROWN);
  putpixel(xc-Y,yc-X,BROWN);
 }
//Bresenham Circle Algorithm
 void Bresenham(int xc,int yc,int r)
  {
   int X,Y;
   X=0,Y=r;
   display(xc,yc,X,Y);
   int sum=3-2*r;
   while(X<=Y)
    {
     if(sum<0)
      {
       sum+=4*X+6;
      }
     else
      {
       Y--;
       sum+=4*X-4*Y+10;
      }
     X++;
     display(xc,yc,X,Y);
    }
  }

//Mid-Point Circle Drawing Function
 void midptcirc(int xc,int yc,int r)
  {
   int X,Y;
   X=0,Y=r;
   display(xc,yc,X,Y);
   int p=1-r;
   while(X<=Y)
    {
     if(p<0)
      {
       p+=2*X+1;
      }
     else
      {
       Y--;
       p+=2*X-2*Y+1;
      }
     X++;
     display(xc,yc,X,Y);
    }
  }

//OBJECT
 void clock()
  {
    int i=1;
    Bresenham(320,240,150);
    while((150-i)!=110)
     {
      Bresenham(320,240,150-i);
      midptcirc(320,240,150-i);
      i++;
     }
    midptcirc(320,240,110);
    settextstyle(6,0,3);
    outtextxy(310,133,"12");
    outtextxy(400,225,"3");
    outtextxy(320,310,"6");
    outtextxy(213,225,"9");
    line(320,240,350,165);
    line(320,240,260,240);
    getch();
  }

 void main(){
   clrscr();
   int gd=DETECT,gm;
   int opt,radius,xc,yc;
   cout<<" <TEXT MODE> "<<endl;
   cout<<"Enter the option number:\n1. Bresenham Cricle Algorithm\t2. Mid-Point Circle Algorithm\t3. Draw a Object\t";
   cin>>opt;
   if(opt==1 || opt==2)
    {
     cout<<"Enter the radius:\t";
     cin>>radius;
     cout<<"Enter Centre X co-ordinate and Centre Y co-ordinate respectively:\t";
     cin>>xc>>yc;
    }
   else;
   getch();
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   cout<<" <GRAPHICS MODE> "<<endl;
   switch(opt)
    {
     case 1:
      {
       Bresenham(xc,yc,radius);
       break;
      }
     case 2:
      {
       midptcirc(xc,yc,radius);
       break;
      }
     case 3:
      {
       clock();
       break;
      }
     default:
      {
       break;
      }
    }
   getch();
   closegraph();
   cout<<" <TEXT MODE> "<<endl;
   cout<<"\n\n\n\t\t\tEND OF TESTING"<<endl;
   getch();
  }