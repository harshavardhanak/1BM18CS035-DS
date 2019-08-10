#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stack[100],top=-1;
void push();
void pop();
void display();
void main()
{
 int c;
 while(1)
 {
 printf("n1.Push\nn2.pop\nn3.Display\nn4.Exit\n");
 printf("Enter the choice:\n ");
 scanf("%d",&c);
 switch(c)
 {
  case 1:push();
         break;
case 2:pop();
         break;
case 3:display();
         break;
  case 4:exit(0);
default:printf("invalid choice");
}
}
}
void push()
{ int ele;
   if(top==99)
   {printf("Stack is overflow");}
   else
   {printf("Enter the value");
   scanf("%d",&ele);
   top=top+1;
   stack[top]=ele;}
}
void pop()
{
  if(top==-1)
  {printf("Stack is underflow");}
  else
  {printf("Deleted element =%d\n",stack[top]);
  top=top-1;}
  }
 void display()
 {int i;
 if(top==-1)
 {printf("stack is underflow");}
 else
 for(i=top;i>=0;i--)
 {printf("%d\n",stack[i]);}
}
