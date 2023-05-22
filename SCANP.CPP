#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
 void main(){
   int n,i,j,k,gd=DETECT,gm,dx,dy;
   int yy,temp;
   int x[20],y[20],xi[20];
   float slope[20];
   clrscr();
   cout<<"Enter number of edges:-\t";
   cin>>n;
   for(i=0;i<n;i++)
    {
     cout<<"Enter X and Y coordinate of vertex "<<i+1<<" :\t";
     cin>>x[i]>>y[i];
    }
   x[n]=x[0];
   y[n]=y[0];
   getch();
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   for(i=0;i<n;i++)
    {
     line(x[i],y[i],x[i+1],y[i+1]);
    }
   getch();
   for(i=0;i<n;i++)
    {
     dy=y[i+1]-y[i];
     dx=x[i+1]-x[i];
     if(dy==0) slope[i]=1.0;
     else if(dx==0) slope[i]=0.0;
     else if((dy!=0) && (dx!=0))
      {
       slope[i]=(float)dx/dy;
      }
     }
   for(yy=0;yy<=480;yy++)
    {
     k=0;
    for(i=0;i<n;i++){
     if(((y[i]<=yy)&&(y[i+1]>yy)) || ((y[i]>yy)&&(y[i+1]<=yy)))
      {
       xi[k]=(int)(x[i]+slope[i]*(yy-y[i]));
       k++;
      }
     }
    for(j=0;j<k-1;j++)
     {
      for(i=0;i<k-1;i++)
       {
	if(xi[i]>xi[i+1])
	 {
	  temp=xi[i];
	  xi[i]=xi[i+1];
	  xi[i+1]=temp;
	 }
	 }
       }
      setcolor(RED);
      for(i=0;i<k-1;i++)
       {
	line(xi[i],yy,xi[i+1],yy);
       }
     }
   getch();
   closegraph();
   getch();
  }