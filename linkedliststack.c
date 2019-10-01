#include<stdlib.h>
#include<stdio.h>
 struct node
 {
  int data;
  struct node *next;
 };
 typedef struct node *n1;
 n1 getnode()
  {
    n1 p;
    p=(n1)malloc(sizeof(n1));
    if(p!=NULL){
     return p;}
   }
   n1 insert_front(n1 head,int item)
   {
     n1 p;
     p=getnode();
     p->data=item;
     p->next=head;
     head=p;
     return head;
    }
    n1 delete_front(n1 head)
    {
     n1 p=head;
     if(head==NULL){
     printf("List is empty");
     return NULL;}
     printf("Deleted element=%d\n",p->data);
     head=p->next;
     free(p);
     return head;
    }
    void display(n1 head)
    {
     n1 p;
     if(head==NULL)
     {
     printf("List is empty");
     return;}
     p=head;
     while(p!=NULL){
     printf("%d\n",p->data);
     p=p->next;}
    }
   int main()
   {
    n1 head=NULL;
    int ele,ch;
    while(1)
            {
              printf("1.push\n2.pop\n3.Display\n4.exit\n");
              printf("Enter the choice");
              scanf("%d",&ch);
              switch(ch)
                        {
                         case 1:printf("Enter the element");
                                scanf("%d",&ele);
                                head=insert_front(head,ele);
                                break;
                          case 2:head=delete_front(head);
                                 break;
                          case 3:printf("Elements of list are\n");
                                 display(head);
                                 break;
                          case 4:exit(0);
                                 break;
                          }
              }
      } 
     
 
