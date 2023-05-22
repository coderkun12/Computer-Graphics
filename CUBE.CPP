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
   cout<<"----------CUBE CODE----------";
   rectangle(120,200,300,400);
   rectangle(90,100,250,350);
   setcolor(RED);
   line(90,100,120,200);
   setcolor(GREEN);
   line(250,100,300,200);
   setcolor(BROWN);;
   line(90,350,120,400);
   setcolor(BLUE);
   line(250,350,300,400);
   getch();
   closegraph();
  }