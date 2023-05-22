#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include "BRESENHA.CPP"
  void drawpoly(int x[],int y[],int n,int col)
  {
  int j;
   for(j=0;j<n-1;j++)
     {
      Bresenham(x[j],y[j],x[j+1],y[j+1],col);
     }
    if(n!=2)
     {
      Bresenham(x[j],y[j],x[j+1],y[j+1],col);
     }
 }

 void main(){
  int gd=DETECT,c,gm,n,i,x[10],y[10],opt,shx;
  double theta;
  clrscr();
  cout<<" <TEXT MODE>\n";
  cout<<"Enter how many vertices are in your 2D-figure (Should have min. 2):\t";
  cin>>n;
  cout<<"Enter what do you wish to perform:\n0.Exit\t1. Rotation\t2. Reflection @ Y-axis\t3. X-shear"<<endl;
  cin>>opt;
  if(opt==2)
   {
    cout<<"Please enter the co-ordinates (X in range 320<=x<=640):"<<endl;
   }
  else{
    cout<<"Please enter the co-ordinates:"<<endl;
   }
  for(i=0;i<n;i++)
   {
    cout<<"Enter X co-ordinate of "<<i+1<<" vertex:\t";
    cin>>x[i];
    cout<<"Enter Y co-ordinate of "<<i+1<<" vertex:\t";
    cin>>y[i];
   }
  if(n!=2){
   x[n]=x[0];
   y[n]=y[0];
  }
  switch(opt)
   {
    case 1:
     {
      cout<<"Enter the angle:\t";
      cin>>theta;
      initgraph(&gd,&gm,"C:/TURBOC3/BGI");
      cout<<" <Graphics Mode> "<<endl;
      cout<<"Green: Original"<<endl;
      cout<<"Yellow: Rotated"<<endl;
      drawpoly(x,y,n,GREEN);
      float x1,y1,x2,y2;
      for(i=0;i<n;i++)
       {
	x1=(int)(x[i]*cos(theta*M_PI/180))+(y[i]*(-sin(theta*M_PI/180)));
	y1=(int)(x[i]*(sin(theta*M_PI/180)))+(y[i]*cos(theta*M_PI/180));
	x2=(int)(x[i+1]*cos(theta*M_PI/180))+(y[i+1]*(-sin(theta*M_PI/180)));
	y2=(int)(x[i+1]*(sin(theta*M_PI/180)))+(y[i+1]*cos(theta*M_PI/180));
	Bresenham(320-x1,y1,320-x2,y2,YELLOW);
       }
      if(n!=2)
       {
	x1=(int)(x[i]*cos(theta*M_PI/180))+(y[i]*(-sin(theta*M_PI/180)));
	y1=(int)(x[i]*(sin(theta*M_PI/180)))+(y[i]*cos(theta*M_PI/180));
	x2=(int)(x[i+1]*cos(theta*M_PI/180))+(y[i+1]*(-sin(theta*M_PI/180)));
	y2=(int)(x[i+1]*(sin(theta*M_PI/180)))+(y[i+1]*cos(theta*M_PI/180));
	Bresenham(320-x1,y1,320-x2,y2,YELLOW);
       }
      break;
     }
    case 2:
     {
      initgraph(&gd,&gm,"C:/TURBOC3/BGI");
      Bresenham(320,0,320,480,WHITE);
      cout<<"Original Figure in 'Green'"<<endl;
      drawpoly(x,y,n,GREEN);
      delay(300);
      cout<<"Reflected Image in 'Blue'"<<endl;
      for(i=0;i<n;i++)
       {
	c=x[i]-320;
	x[i]=c;
       }
      x[n]=x[0];
      drawpoly(x,y,n,BLUE);
      break;
     }
    case 3:
     {
      cout<<"Enter the shear about X-Axis:\t";
      cin>>shx;
      initgraph(&gd,&gm,"C:/TURBOC3/BGI");
      drawpoly(x,y,n,RED);
      int c;
      for(i=0;i<n;i++)
       {
	c=x[i]+(shx*y[i])-320;
	x[i]=c;
       }
      x[4]=x[0];
      drawpoly(x,y,n,BROWN);
      break;
     }
    default:
     {
      break;
     }
   }
  getch();
  closegraph();
  getch();
 }