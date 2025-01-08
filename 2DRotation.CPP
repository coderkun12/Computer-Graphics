#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
 void main()
  {
   int x[10],y[10];
   int dm,dd=DETECT;
   double thet;
   clrscr();
   cout<<" Enter ther co-ordinates of the polygon:\n";
   for(int i=0;i<3;i++)
    {
     cout<<" X-Coordinate:\t";
     cin>>x[i];
     cout<<" Y-Coordinate:\t";
     cin>>y[i];
    }
  cout<<"Enter the angle of Rotation:\t";
  cin>>thet;
  initgraph(&dd,&dm,"C:/TURBOC3/BGI");
  x[3]=x[0];
  y[3]=y[0];
  cout<<"ORIGINAL";
  for(i=0;i<3;i++)
   {
    line(x[i],y[i],x[i+1],y[i+1]);
   }
  setcolor(RED);
  cout<<"\nRotated Image";
  float x1,y1,x2,y2;
  for(i=0;i<3;i++)
   {
    x1=(int)(x[i]*cos(thet*M_PI/180))+(y[i]*(-sin(thet*M_PI/180)));
    y1=(int)(x[i]*(sin(thet*M_PI/180)))+(y[i]*cos(thet*M_PI/180));
    x2=(int)(x[i+1]*cos(thet*M_PI/180))+(y[i+1]*(-sin(thet*M_PI/180)));
    y2=(int)(x[i+1]*(sin(thet*M_PI/180)))+(y[i+1]*cos(thet*M_PI/180));
    line(320-x1,y1,320-x2,y2);
   }
  getch();
  closegraph();
  getch();
 }
