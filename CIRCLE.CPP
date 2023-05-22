#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void main()
 {
  clrscr();
  int xco,yco;
  int radius=90;
  int gd=DETECT,gm;
   cout<<"Enter X coordinate of circle:\t";
  cin>>xco;
  cout<<"Enter Y coordinate of circle:\t";
  cin>>yco;
  initgraph(&gd,&gm,"C:/TURBOC3/BGI");
  int bcolo=15;
  setfillstyle(7,4);
  circle(xco,yco,radius);
  floodfill(xco,yco,bcolo);
  getch();
  closegraph();
 }
