#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insertfront(int item,NODE head);
NODE insertpos(NODE head,int item,int pos);
NODE insertend(int item,NODE head);
NODE getnode()
{
 NODE p;
 p=(NODE)malloc(sizeof(struct node));
 if(p!=NULL)
 return p;
 else
 printf("Could not be allocated");
 exit(0);
}
NODE insertfront(int item,NODE head)
{
 NODE p;
 p=getnode();
 p->data=item;
 p->next=head;
 head=p;
 return head;
}
void display(NODE head)
{
 NODE p;
 if(head==NULL);
 {
 printf("Linkedlist is empty");
 exit(0);
 }
 else
 {
 p=head;
 }
 while(p!=NULL)
 {
 printf("%d",p->data);
 p=p->data;
 }
}
NODE insertpos(NODE head,int item,int pos)
{ int p;
 NODE curr,new;
 NODE prev=NULL;
 int count;
 p=getnode();
 p->data=item;
 p->next=NULL;
 if(head==NULL)
 {
  if(pos==1)
   return p;
 }
 printf("Invalid position");
 if(pos==1)
 {
 p->next=head;
 head=p;
 return head;
 }
 else
 {
 curr=head;
 count=1;
 while((curr!=NULL)&&(count!=pos))
 {
  prev=curr;
  curr=curr->next;
  count++;
 }
 if(count==pos)
 {
  prev->next=p;
  p->next=curr;
  return head;
 }
 else
 {
  printf(("Invalid position");
  return head;
 }
 }
 void insertend(int item,NODE head)
 {
 NODE p,q;
 q=getnode();
 q->data=item;
 p=head;
 while(p->next!=NULL)
  {
   p=p->next;
   }
  p->next=q;
  q->next=NULL;
 }
void main()
{
 int ch;
 NODE head=NULL; 
 while(1)
 {
 
  printf("1=insertfront,2=insertpos,3=insertend,4=exit\n");
  printf("Enter the choice");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:
           head=insertfront(60,head);
           display(head);
           break;
    case 2:
           head=insertpos(head,70,2);
           display(head);
           head=insertpos(head,50,30);
           display(head);
           break;
    case 3:insertend(89,head);
           display(head);
           break;
    case 4:exit(0);
  }
 }
 }
       
