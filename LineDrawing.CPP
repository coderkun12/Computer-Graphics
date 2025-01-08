//WRITE A MENU DRIVEN PROGRAM TO IMPLEMENT DDA,BRESENHAM LINE DRAWING ALGORITHM ALSO DRAW A OBJECT USING LINE.
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

//DDA ALGO FUNC
 int round(float n)
  {
   if(n-(int)n <0.5)
    {
     return (int)n;
    }
   return (int)(n+1);
  }
//DDA ALGO FUNC
 void DDA(int x1,int y1,int x2,int y2)
  {
   int steps,dx,dy;
   dx=x2-x1;
   dy=y2-y1;
   if(abs(dx)>=abs(dy))
    {
      steps=dx;
    }
   else
    {
     steps=dy;
    }
   float xinc=dx/(float)steps;
   float yinc=dy/(float)steps;
   float X=x1;
   float Y=y1;
   for(int i=0;i<steps;i++)
    {
     putpixel(round(X),round(Y),RED);
     X+=xinc;
     Y+=yinc;
    }
    setcolor(RED);
    line(x1,y1,x2,y2);
  }

//BRESENHAM ALGORITHM
 void Bresenham(int x1,int y1,int x2,int y2)
  {
   int dy=abs(y2-y1);
   int dx=abs(x2-x1);
   int p,x,y;
   x=x1;
   y=y1;
  if(dx>=dy) //GENTLE SLOPE
   {
    p=2*dy-dx;
    do{
     putpixel(x,y,WHITE);
     if(p>0)
      {
       if(y1<y2)
	{
	  y++;
	}
       else{
	  y--;
	}
       p=p+2*dy-2*dx;
      }
     else
      {
	p=p+2*dy;
      }
     if(x1<x2)
      {
       x++;
      }
     else
      {
       x--;
      }
    }while(x!=x2);
   }
  else   //STEEP SLOPE
   {
    p=2*dx-dy;
    do{
     putpixel(x,y,WHITE);
     if(p>0)
      {
       if(x1<x2)
	{
	 x++;
	}
       else
	{
	 x--;
	}
       p=p+2*dx-2*dy;
      }
     else
      {
       p=p+2*dx;
      }
     if(y1<y2)
      {
       y++;
      }
     else
      {
       y--;
      }
    }while(y!=y2);
   }
 }

//CREATES A HOUSE
 void House()
  {
       DDA(100,350,250,350);
       DDA(100,350,100,200);
       DDA(250,350,250,200);
       DDA(250,350,512,300);
       DDA(512,150,512,300);
       DDA(100,200,250,200);
       DDA(250,200,512,150);
       DDA(175,100,450,50);
       DDA(450,50,512,150);
       DDA(175,100,100,200);
       DDA(175,100,250,200);
       circle(175,160,20);
       Bresenham(145,350,145,268);
       Bresenham(205,350,205,268);
       Bresenham(205,268,145,268);
  }

//MAIN FUNCTION
 void main()
  {
   clrscr();
   int gd,gm;
   gd=DETECT;
   int x1,x2,y1,y2,opt,dx,dy;
   cout<<"  <TEXT MODE> "<<endl;
   cout<<"What do you wish to do?\n1. DDA\t2. Bresenham Algorithm\t3. Draw a House"<<endl;
   cin>>opt;
   switch(opt)
   {
    case 1:
     {
      cout<<"-----DDA ALGORITHM------";
      cout<<"Enter coordinates x1 y1 x2 y2 respectively:\t";
      cin>>x1>>y1>>x2>>y2;
      initgraph(&gd,&gm,"C:/TURBOC3/BGI");
      cout<<"  <GRAPHICS MODE> "<<endl;
      DDA(x1,y1,x2,y2);
      break;
     }
    case 2:
     {
      cout<<"Enter coordinates x1 y1 x2 y2 respectively:\t";
      cin>>x1>>y1>>x2>>y2;
      initgraph(&gd,&gm,"C:/TURBOC3/BGI");
      cout<<"  <GRAPHICS MODE> "<<endl;
      Bresenham(x1,y1,x2,y2);
      break;
     }
   case 3:
     {
      initgraph(&gd,&gm,"C:/TURBOC3/BGI");
       cout<<"  <GRAPHICS MODE> "<<endl;
      House();
      break;
     }
   default:
    {
     break;
    }
   }
   getch();
   closegraph();
   cout<<" <TEXT MODE> ";
   cout<<"\n\n\t\t\tEND OF TESTING";
   getch();
  }
