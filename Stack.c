#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
void push(int a[100],int *t);
void pop(int a[100],int *t);
void display(int a[100],int *t);
void main()
{
 int a[100],top=-1,c;
 while(1)
 {
  printf("n1.Push\nn2.Pop\nn3.Display\nn4.Exit\n");
  printf("Enter the choice:\n");
  scanf("%d",&c);
  switch(c)
  {
  case 1:push(a,&top);
         break;
  case 2:pop(a,&top);
         break;
  case 3:display(a,&top);
         break;
   case 4:exit(0);
   default:printf("Invalid choice:\n");
  }
 }
}
void push(int a[100],int *t)
{
int ele;
if(*t==99)
printf("Stack is overflow\n");
else
printf("Enter the element:\n");
scanf("%d",&ele);
*t=*t+1;
a[*t]=ele;
}
void pop(int a[100],int *t)
{
 int del;
 if(*t==-1)
 {
     printf("Stack is underflow\n");
     exit(0);
 }

 else
 del=a[*t];
 *t=*t-1;
 printf("Popped element =%d",del);
}
void display(int a[100],int *t)
{int i;
 if(*t==-1)
 printf("Stack is underflow\n");
 else
 for(i=*t;i>=0;i--)
 printf("%d\n",a[i]);
}
