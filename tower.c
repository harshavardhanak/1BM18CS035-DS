#include<stdio.h>
void tower(int n,char x,char y,char z);
int main()
{
 int n;
printf("Enter the number of plates:\n");
scanf("%d",&n);
tower(n,'A','B','C');
return 0;
}
void tower(int n,char x,char y,char z)
{
 if(n==1)
{
 printf("1 plate is moved from %c to %c\n",x,z);
}
else if(n>0)
{
tower(n-1,x,z,y);
printf("%d platte is moved from %c to %c\n",n,x,z);
tower(n-1,y,x,z);
}
} 
