//WAP to do the following: Boundary Fill, Edge Fill,Scan Line Fill.
#include<stdio.h>
#include<stdlib.h>
#include"Bresenham.CPP"
#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<math.h>

//For Queue
struct node{
  int x, y;
  struct node* next;
};

//Enqueue operation
 struct node* enq(struct node* head,int x,int y)
 {
  struct node* newn=(struct node*)malloc(sizeof(struct node));
  if(newn==NULL)
   {
    return head;
   }
  else{
  newn->x=x;
  newn->y=y;
  if(head==NULL)
   {
    head=newn;
    head->next=NULL;
    return head;
   }
  else
   {
     head->next=newn;
     head=newn;
     newn->next=NULL;
     return head;
   }
 }
}
//Delqueue operation
struct node* deq(struct node* head)
 {
  if(head==NULL)
   {
    return NULL;
   }
  struct node* k;
  k=head;
  head=k->next;
  k->next=NULL;
  free(k);
  return head;
 }

 //Boundary Fill Algorithm
void Boundary_Fill(int x,int y)
{
 struct node* rear=NULL;
 struct node* head=NULL;
 putpixel(x,y,RED);
 rear=enq(rear,x+1,y);
 head=rear;
 putpixel(x+1,y,RED);
 rear=enq(rear,x-1,y);
 putpixel(x-1,y,RED);
 rear=enq(rear,x,y+1);
 putpixel(x,y+1,RED);
 rear=enq(rear,x,y-1);
 putpixel(x,y-1,RED);
 while(head!=rear)
  {
   x=head->x;
   y=head->y;
   putpixel(x,y,RED);
   head=deq(head);
   if(getpixel(x+1,y)==0)
    {
     rear=enq(rear,x+1,y);
    }
    if(getpixel(x-1,y)==0)
    {
     rear=enq(rear,x-1,y);
    }
    if(getpixel(x,y+1)==0)
    {
     rear=enq(rear,x,y+1);
    }
    if(getpixel(x,y-1)==0)
    {
     rear=enq(rear,x,y-1);
    }
  }
}

//Checks if seed point inside polygon for boundary fill
int odd_even(int seedx,int seedy,int limx)
 {
  int gp;
  int x=seedx;
  int counter=0;
  int y=seedy;
  while(x>=limx)
   {
    gp=getpixel(x,y);
    if(gp!=0)
     {
      counter+=1;
     }
    x--;
   }
  if(counter%2==0)
   {
    return 0;
   }
  else
   {
    return -1;
   }
 }

//Edge Fill Function
 void edgef(int X,int Y)
 {
	while(X<640)
	 {
	  if(getpixel(X,Y)==0)
	   {
	    putpixel(X,Y,YELLOW);
	   }
	  else if(getpixel(X,Y)==14)
	   {
	    putpixel(X,Y,BLACK);
	   }
	  X++;
       }
 }

void edge_fill(int x1,int y1,int x2,int y2)
 {
  int dx,dy,p;
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  int x=x1;
  int y=y1;
    p=2*dx-dy;
    do{
    if(y2-y1!=0)
    {
     edgef(x,y);
    }
    else;
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
   edgef(x,y);
 }

//Scanline Algorithm
 void scanline(int x[],int y[],int n)
  {
   float dx,dy,slope[50];
   int yy,i,k,inter_x[50],temp,ymax=0,ymin=480;
   for(i=0;i<n;i++)
    {
     if(y[i]>=ymax)
      {
       ymax=y[i];
      }
     if(y[i]<=ymin)
      {
       ymin=y[i];
      }
     dx=x[i+1]-x[i];
     dy=y[i+1]-y[i];
     if(dx==0)
      {
       slope[i]=0;
      }
     if(dy==0)
      {
       slope[i]=1;
      }
    }
   int cnt;
   for(yy=ymax;yy>=ymin;yy--)
    {
     cnt=0;
     for(i=0;i<n;i++)
      {
       if((y[i] && y[i+1]<=0) || y[i]<=yy && y[i+1]>yy)
	{
	 inter_x[cnt]=(x[i]+(slope[i]*(yy-y[i])));
	 cnt++;
	}
      }
     for(k=0;k<cnt-1;k++)
      {
	for(i=0;i<cnt-1;i++)
	 {
	  if(inter_x[i]>inter_x[i+1])
	   {
	    temp=inter_x[i];
	    inter_x[i]=inter_x[i+1];
	    inter_x[i+1]=temp;
	   }
	 }
      }
     for(i=0;i<cnt-1;i++)
      {
       Bresenham(inter_x[i],yy,inter_x[i+1]+1,yy,BLUE);
      }
     }
    getch();
  }
//Function to draw polygon
void draw_poly(int x[],int y[],int n)
 {
  int j;
   for(j=0;j<n-1;j++)
     {
      Bresenham(x[j],y[j],x[j+1],y[j+1],BLUE);
     }
    Bresenham(x[0],y[0],x[n-1],y[n-1],BLUE);
 }

//Main Function
void main()
 {
  clrscr();
  int minx,option,gd,gm,n,i,j,seedx,seedy;
  gd=DETECT;
  int x[10],y[10];
  cout<<" <TEXT MODE>"<<endl;
  cout<<"Enter number of vertices:\t";
  cin>>n;
  for(i=0;i<n;i++)
   {
    cout<<"\nEnter X:\t";
    cin>>x[i];
    cout<<"Enter Y:\t";
    cin>>y[i];
   }
  cout<<"Enter which option do you wish to perform:\n1. Boundary Fill\t2. Edge Fill\t3. Scan Line Fill\t";
  cin>>option;
  switch(option)
   {
    case 1:
    {
     cout<<"Enter seed coordinates (x,y):\t";
     cin>>seedx>>seedy;
     minx=999;
     for(i=0;i<n;i++)
      {
       if(x[i]<minx)
	{
	 minx=x[i];
	}
      }
     getch();
     initgraph(&gd,&gm,"C:/TURBOC3/BGI");
     cout<<" <GRAPHICS MODE>";
     draw_poly(x,y,n);
     getch();
     int u;
     u=odd_even(seedx,seedy,minx-20);
     if(u==-1)
     {
      Boundary_Fill(seedx,seedy);
     }
    else
     {
      cout<<"Seed point is outside hence cannot draw the polygon!";
     }
     break;
   }
   case 2:
    {
     initgraph(&gd,&gm,"C:/TURBOC3/BGI");
     cout<<" <GRAPHICS MODE> "<<endl;
     draw_poly(x,y,n);
     getch();
     y[n]=y[0];
     x[n]=y[0];
     for(i=0;i<n;i++)
      {
       edge_fill(x[i],y[i],x[i+1],y[i+1]);
      }
     getch();
     closegraph();
     break;
    }
   case 3:
    {
     initgraph(&gd,&gm,"C:/TURBOC3/BGI");
     cout<<" <GRAPHICS MODE> "<<endl;
     draw_poly(x,y,n);
     scanline(x,y,n);
     getch();
     closegraph();
     break;
    }
   default:
    {
     break;
    }
  }
  getch();
 }