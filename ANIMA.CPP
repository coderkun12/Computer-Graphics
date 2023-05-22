#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<graphics.h>
#include "BRECIRC.CPP"

//Linked List.
struct node{
 struct node *next,*prev;
 int x,y;
};

struct node* enq(struct node* head,int x,int y)
 {
  if(head->x==x && head->y==y)
  {
   return head;
  }
  else{
   struct node * newn=(struct node*)malloc(sizeof(struct node));
   if(newn==NULL)
    {
     return head;
    }
   else
    {
     if(head==NULL)
      {
       head=newn;
       head->prev=NULL;
       head->next=NULL;
       head->x=x;
       head->y=y;
       return head;
      }
     else{
     newn->x=x;
     newn->y=y;
     newn->next=NULL;
     head->next=newn;
     newn->prev=head;
     head=head->next;
     return head;
    }
   }
 }
}

//To get the pixels which would be turned on in the outer circle.
 struct node* generate(struct node* head,int rad)
 {
  int X=0;
  int Y=rad;
  head=enq(head,X,Y);
  int p=3-2*rad;
  do{
   if(p>0)
    {
     Y--;
     X++;
     p=p+4*(X-Y)+10;
    }
   else
    {
     X++;
     p=p+4*X+6;
    }
   head=enq(head,X,Y);
  }while(X<=Y);
  return head;
 }

//Clockwise rotation of ball.
 void clockwise(struct node *front,struct node* head,int xc,int yc)
  {
  struct node* temp=front;
  while(temp!=NULL)
   {
    brcircle(xc+temp->x,yc-temp->y,20,BLUE);
    delay(30);
    brcircle(xc+temp->x,yc-temp->y,20,BLACK);
    temp=temp->next;
   }
   temp=head;
  while(temp!=NULL)
   {
    brcircle(xc+temp->y,yc-temp->x,20,BLUE);
    delay(30);
    brcircle(xc+temp->y,yc-temp->x,20,BLACK);
    temp=temp->prev;
   }
   temp=front;
  while(temp!=NULL)
   {
    brcircle(xc+temp->y,yc+temp->x,20,BLUE);
    delay(30);
    brcircle(xc+temp->y,yc+temp->x,20,BLACK);
    temp=temp->next;
   }
   temp=head;
  while(temp!=NULL)
   {
    brcircle(xc+temp->x,yc+temp->y,20,BLUE);
    delay(30);
    brcircle(xc+temp->x,yc+temp->y,20,BLACK);
    temp=temp->prev;
   }
    temp=front;
  while(temp!=NULL)
   {
    brcircle(xc-temp->x,yc+temp->y,20,BLUE);
    delay(30);
    brcircle(xc-temp->x,yc+temp->y,20,BLACK);
    temp=temp->next;
   }
   temp=head;
  while(temp!=NULL)
   {
    brcircle(xc-temp->y,yc+temp->x,20,BLUE);
    delay(30);
    brcircle(xc-temp->y,yc+temp->x,20,BLACK);
    temp=temp->prev;
   }
   temp=front;
  while(temp!=NULL)
   {
    brcircle(xc-temp->y,yc-temp->x,20,BLUE);
    delay(30);
    brcircle(xc-temp->y,yc-temp->x,20,BLACK);
    temp=temp->next;
   }
   temp=head;
  while(temp!=NULL)
   {
    brcircle(xc-temp->x,yc-temp->y,20,BLUE);
    delay(30);
    brcircle(xc-temp->x,yc-temp->y,20,BLACK);
    temp=temp->prev;
   }
  }

//Anti-clockwise movement of ball.
 void anticlockwise(struct node* front,struct node* head,int xc,int yc)
  {
  struct node* temp=front;
  while(temp!=NULL)
   {
    brcircle(xc-temp->x,yc-temp->y,20,BLUE);
    delay(30);
    brcircle(xc-temp->x,yc-temp->y,20,BLACK);
    temp=temp->next;
   }
   temp=head;
   while(temp!=NULL)
   {
    brcircle(xc-temp->y,yc-temp->x,20,BLUE);
    delay(30);
    brcircle(xc-temp->y,yc-temp->x,20,BLACK);
    temp=temp->prev;
   }
   temp=front;
   while(temp!=NULL)
   {
    brcircle(xc-temp->y,yc+temp->x,20,BLUE);
    delay(30);
    brcircle(xc-temp->y,yc+temp->x,20,BLACK);
    temp=temp->next;
   }
   temp=head;
   while(temp!=NULL)
   {
    brcircle(xc-temp->x,yc+temp->y,20,BLUE);
    delay(30);
    brcircle(xc-temp->x,yc+temp->y,20,BLACK);
    temp=temp->prev;
   }
   temp=front;
   while(temp!=NULL)
   {
    brcircle(xc+temp->x,yc+temp->y,20,BLUE);
    delay(30);
    brcircle(xc+temp->x,yc+temp->y,20,BLACK);
    temp=temp->next;
   }
   temp=head;
   while(temp!=NULL)
   {
    brcircle(xc+temp->y,yc+temp->x,20,BLUE);
    delay(30);
    brcircle(xc+temp->y,yc+temp->x,20,BLACK);
    temp=temp->prev;
   }
    temp=front;
   while(temp!=NULL)
   {
    brcircle(xc+temp->y,yc-temp->x,20,BLUE);
    delay(30);
    brcircle(xc+temp->y,yc-temp->x,20,BLACK);
    temp=temp->next;
   }
   temp=head;
   while(temp!=NULL)
   {
    brcircle(xc+temp->x,yc-temp->y,20,BLUE);
    delay(30);
    brcircle(xc+temp->x,yc-temp->y,20,BLACK);
    temp=temp->prev;
   }
  }

 void main()
  {
   struct node* head=NULL;
   clrscr();
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:/TURBOC3/BGI");
   setfillstyle(1,5);
   brcircle(320,240,70,RED);
   floodfill(320,240,RED);
   getch();
   head=generate(head,90);
   struct node* front=head;
   while(front->prev!=NULL)
    {
     front=front->prev;
    }
   clockwise(front,head,320,240);
   anticlockwise(front,head,320,240);
   delay(100);
   cleardevice();
   cout<<" ANIMATION OVER! PRESS ENTER TO EXIT";
   getch();
   closegraph();
  }