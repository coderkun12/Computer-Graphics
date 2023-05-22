#include<stdio.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
 void main()
  {
   //ellipse(x,y,stangle,endangle,xradius,yradius);
   clrscr();
   int gd=DETECT,gm;
   int x,y,xrad,yrad;
   //int stangle,endangle;
   cout<<" <TEXT MODE> "<<endl;
   cout<<"----------ELLIPSE CODE----------"<<endl;
   cout<<"Enter the centre co-ordinates:\t";
   cin>>x>>y;
   //cout<<"Enter start angle and end angle:\t";
   //cin>>stangle>>endangle;
   cout<<"Enter the x-radius and y-radius:\t";
   cin>>xrad>>yrad;
   getch();
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   cout<<" <GRAPHICS MODE> "<<endl;
   cout<<" YOUR ELLIPSE IS AS FOLLOWS:\n";
   setcolor(RED);
   ellipse(x,y,0,360,xrad,yrad);
   //setcolor(GREEN);
   //ellipse(x,y,0,360,xrad+20,yrad+20);
   getch();
   closegraph();
  }