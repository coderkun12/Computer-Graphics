#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
 void main()
  {
   clrscr();
   int gd,gm;
   gd=DETECT;
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   cout<<" <GRAPHICS MODE> "<<endl;
   cout<<"----------CAR CODE----------";
  // setcolor();
   line(100,200,110,200);
   line(390,200,400,200);
   line(50,300,450,300);
   line(100,200,50,300);
   line(400,200,450,300);
   setcolor(RED);
   circle(140,310,30);
   circle(360,310,30);
   setcolor(BLUE);
   line(110,200,150,150);
   line(390,200,350,150);
   line(150,150,350,150);
   setcolor(GREEN);
   line(250,150,250,200);
   line(250,200,390,200);
   line(110,200,250,200);
   setcolor(BROWN);
   line(0,340,640,340);
   getch();
   closegraph();
  }