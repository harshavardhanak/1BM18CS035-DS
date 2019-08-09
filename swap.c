#include<stdio.h>
#include<conio.h>
void swap(int *x,int *y);
void main()
{
int a,b;
printf("Enter the numbers:");
scanf("%d%d",&a,&b);
printf("Two numbers before swapping are %d and %d",a,b);
swap(&a,&b);
printf("Two numbers after swapping are %d and %d",a,b);
getch();
}
void swap(int *x,int *y)
{
  int t;
  t=*x;
  *x=*y;
  *y=t;
}
