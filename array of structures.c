#include<stdio.h>
#include<conio.h>
struct student
{
int id,age,marks;
};
void main()
{
 struct student s[100];
 int n,i;
 clrscr();
 printf("Enter the number of students: ")
 scanf("%d",&n);
 printf("Enter the id ,age and marks of student :");
 for(i=0;i<n;i++)
 scanf("%d%d%d",&s[i].id,&s[i].age,&s[i].marks);
 for(i=0;i<n;i++)
 if((s[i].age>20)&&(s[i].marks>0)&&(s[i].marks<100))
 {
   if(s[i].marks>65)
   printf("Student %d data is valid and eligible for admission\n",i+1);
   else
   printf("Student %d data is valid and not eligible for admission\n ",i+1);
 }
 else
 printf("Student %d data is invalid",i+1);
 getch();
}
