#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE p;
    p=(NODE)malloc(sizeof(struct node));
    return p;
}
NODE insert(NODE head,int item)
{
    NODE p,q=head;
    p=getnode();
    p->data=item;
    if(head==NULL)
    {
        p->next=NULL;
        head=p;
        return p;
    }
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=p;
    p->next=NULL;
    return head;
}
NODE rotate(NODE head,int n)
{
    int i;
    NODE p=head,l=head,q;
    while(l->next!=NULL)
    {
        l=l->next;
    }
    for(i=0;i<n;i++)
    {
        q=p->next;
        head=q;
        l->next=p;
        p->next=NULL;
        l=l->next;
        p=q;
    }
    return head;
}
NODE reverse(NODE head)
{
    NODE prev=NULL,next,curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
void display(NODE head)
{
    NODE p=head;
    if(head==NULL)
    {
        printf("List is empty \n");
        return ;
    }
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
NODE reversen(NODE head,int n)
{
    NODE p=head,q=head,l;
    int c=0;
    while(p!=NULL)
    {
        c++;
        if(c==n)
        {
            l=p->next;
            p->next=NULL;
        }
        p=p->next;
    }
    head=reverse(q);
    q=head;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=l;
    return head;
}
int main()
{
    NODE head=NULL;
    int ch,n,i,ele;
    while(1)
    {
        printf("\n 1.Insertion 2.Rotate 3.Reverse 4.Display 5.Reverse n nodes\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of elements :\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                        printf("Enter the element :\n");
                        scanf("%d",&ele);
                        head=insert(head,ele);
                    }
                   break;
            case 2:printf("Enter the number of nodes to be rotated \n");
                   scanf("%d",&n);
                   head=rotate(head,n);
                   break;
            case 3:head=reverse(head);
                   break;
            case 4:display(head);
                   break;
            case 5: printf("Enter the number of nodes to be reversed :\n");
                    scanf("%d",&n);
                    head=reversen(head,n);
                    break;
            default:exit(0);
        }
    }
    
}