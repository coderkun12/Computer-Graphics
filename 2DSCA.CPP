#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<iostream.h>
 void main()
  {
   int x[10],y[10];
   int sx,sy,dm,dd=DETECT;
   clrscr();
   cout<<" Enter ther co-ordinates of the polygon:\n";
   for(int i=0;i<3;i++)
    {
     cout<<" X-Coordinate:\t";
     cin>>x[i];
     cout<<" Y-Coordinate:\t";
     cin>>y[i];
    }
   cout<<"\nEnter the scaling factor for X coordinates:\t";
   cin>>sx;
   cout<<"Enter the scaling factor for Y coordinates:\t";
  cin>>sy;
  initgraph(&dd,&dm,"C:/TURBOC3/BGI");
  x[3]=x[0];
  y[3]=y[0];
  cout<<"ORIGINAL";
  for(i=0;i<3;i++)
   {
    line(x[i],y[i],x[i+1],y[i+1]);
   }
  getch();
  setcolor(RED);
  cout<<"\nScaled Image";
  for(i=0;i<3;i++)
   {
    line(x[i]*sx,y[i]*sy,x[i+1]*sx,y[i+1]*sy);
   }
  getch();
  closegraph();
  getch();
 }