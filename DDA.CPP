#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<graphics.h>
int round(float n)
 {
  if(n-(int)n<0.5)
   {
    return (int)n;
   }
  return (int)n+1;
 }
void DDA(int x1,int y1,int x2,int y2)
 {
  float X=x1;
  float Y=y1;
  int dx=x2-x1;
  int dy=y2-y1;
  int steps;
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
  int i=0;
  while(i<steps)
   {
    putpixel(round(X),round(Y),RED);
    X+=xinc;
    Y+=yinc;
    i++;
   }
 }
