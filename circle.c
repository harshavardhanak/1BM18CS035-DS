#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    return p;
}
NODE insert(NODE head,int ele)
{
    NODE p,q=head;
    p=getnode();
    p->data=ele;
    if(head==NULL)
    {
        head=p;
        p->next=head;
        return head;
    }
    if(q->next==head)
    {
        q->next=p;
        p->next=head;
        return head;
    }
    while(q->next!=head)
    {
        q=q->next;
    }
    q->next=p;
    p->next=head;
    return head;
}
void display(NODE head)
{
    NODE p=head;
    if(head==NULL)
    {
        printf("List is empty :\n");
        return ;
    }
    do
    {
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=head);
}
NODE reverse(NODE head)
{
    NODE p=head;
    if(head==NULL||p->next==head)
    {
        return p;
    }
    NODE prev=NULL,curr=head,next;
    do
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }while(curr!=head);
    head->next=prev;
    head=prev;
    return head;
}
void sorting(NODE head,int n)
{
    NODE p=head,q;
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        q=p->next;
        for(j=i+1;j<n;j++)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
          q=q->next;
        }
     p=p->next;
    }
}
void concatenate(NODE h1,NODE h2)
{
    NODE p=h1;
    do
    {
        p=p->next;
    }while(p->next!=h1);
    p->next=h2;
    p=h2;
    do
    {
        p=p->next;
    }while(p->next!=h2);
    p->next=h1;
}
NODE rotate(NODE head,int n)
{
    int i;
    NODE q=head;
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    for(i=0;i<n;i++)
    {
        head=q->next;
    }
    return head;
}
int main()
{
    NODE head=NULL;
    NODE head1=NULL;
    int ele,n,i,j,m,ch,count=0;
    while(1)
    {
        printf("\n1.Insertion 2.reverse 3.Sorting 4.Display 5.Concatenate 6.Exit 7.Rotate \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of elements :\n");
                    scanf("%d",&n);
                    count=count+n;
                    for(i=0;i<n;i++)
                    {
                      printf("Enter the element :\n");
                      scanf("%d",&ele);
                      head=insert(head,ele);
                    }
                    break;
            case 2: head=reverse(head);
                    break;
            case 3: sorting(head,count);
                    break;
            case 4: display(head);
                    break;
            case 6:exit(0);
            case 5:printf("Enter the number of elements in second list :\n");
                   scanf("%d",&m);
                  count=count+m;
                   for(j=0;j<m;j++)
                   {
                       printf("Enter the element :\n");
                       scanf("%d",&ele);
                       head1=insert(head1,ele);
                   }
                   concatenate(head,head1);
                   break;
            case 7:printf("Enter the number of nodes to be rotated :\n ");
                   scanf("%d",&n);
                  for(i=0;i<n;i++)
                  {
                      head=rotate(head,n);
                  }
                  break;
        }
    }

}