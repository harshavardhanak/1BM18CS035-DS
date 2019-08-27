#include<stdio.h>
int fibonacci(int n);
int main()
{
 int n,i,a;
 printf("Enter the number:\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
{
 a=fibonacci(i);
 printf("%d",a);
}
return 0;
}
int fibonacci(int n)
{ int c,d;
 if((n==0))
 { return 0;}
else if(n==1)
{ return 1;}
else 
 {c=fibonacci(n-1);
  d=fibonacci(n-2);
return (c+d);}
}

