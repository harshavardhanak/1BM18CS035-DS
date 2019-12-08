#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE n;
    n=(NODE)malloc(sizeof(struct node));
    return n;
}
NODE insertfront(NODE head,int ele)
{
    NODE p;
    p=getnode();
    p->data=ele;
    p->prev=NULL;
    if(head==NULL)
    {
        p->next=NULL;
        head=p;
    }
    else
    {           
        p->next=head;
        head->prev=p;
        head=p;
    }
    return head;
}
void display(NODE head)
{
    NODE p;
    if(head==NULL)
    {
        printf("List is empty:\n");
        return;
    }
    p=head;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
void addright(NODE prevn,int ele)
{
    NODE p;
    p=getnode();
    p->data=ele;
    p->next=prevn->next;
    p->prev=prevn;
    prevn->next=p;    
    p->next->prev=p;
}
void addleft(NODE nextn,int ele)
{
    NODE p;
    p=getnode();
    p->data=ele;
    p->prev=nextn->prev;
    p->next=nextn;
    nextn->prev=p;
    p->prev->next=p;
    
}
void delete(NODE p)
{
    p->prev->next=p->next;
    
}
NODE reverse(NODE head)
{
    NODE p=head,q=NULL;
    while(p!=NULL)
    {
        q=p->prev;
        p->prev=p->next;
        p->next=q;
        p=p->prev;
    }
    head=q->prev;
    return head;
    
}
void sorting(NODE head)
{
    NODE p=head,q;
    int temp;
    while(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
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
NODE rotate(NODE head,int n)
{
    int i;
    NODE p=head,q=head,r;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    for(i=0;i<n;i++)
    {
        r=q->next;
        r->prev=NULL;
        head=r;
        p->next=q;
        q->prev=p;
        q->next=NULL;
        p=p->next;
        q=r;
    }
    return head;
}
void exchange(NODE head)
{
    NODE p=head;
    NODE l=p,s=p;
    int temp,large,small;
    small=p->data;
    p=p->next;
    large=small;
    while(p!=NULL)
    {
       if(p->data>large)
        {
           l=p;
        }
      if (p->data<small)
        {
            s=p;
        }
        p=p->next;
    }
    temp=l->data;
    l->data=s->data;
    s->data=temp;
}
void even(NODE head)
{
    NODE p=head,q;
    while(p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        q->next->prev=p;
        p=p->next;
    }
}
NODE odd(NODE head)
{
    NODE q=head,p;
    p=q->next;
    head=p;
    while(p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        q->next->prev=p;
        p=p->next;        
    }
    return head;
}
void concatenate(NODE h1,NODE h2)
{
    NODE p=h1;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=h2;
}
int main()
{
    NODE head=NULL,head1=NULL;
    NODE p;
    int c,count=0,mount=0,to=0,i,ele,n,pos,m;
    while(1)
    {
        printf("1.Insert front 2.Insert to the right of node 3.Insert to left of node 4.delete 5.display 6.exit 7.Reverse 8.sorting 9.Rotate 10.Exchange 11.Delete even nodes 12.Delete odd nodes 13. concatenate \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the number of elements :\n");
                   scanf("%d",&n);
                   for(i=0;i<n;i++)
                   {
                       printf("Enter the element :\n");
                       scanf("%d",&ele);
                       head=insertfront(head,ele);
                   }
                  break;
            case 2:printf("Enter the prev node and element  :\n");
                   scanf("%d %d",&pos,&ele);
                   p=head;
                   while(p!=NULL)
                   {
                    count++;
                       if(count==pos)
                       {
                           addright(p,ele);
                       }
                       p=p->next;
                   }
                   break;
            case 3:printf("Enter the node and ele:\n");
                   scanf("%d %d",&pos,&ele);
                   p=head;
                   while(p!=NULL)
                   {
                       mount++;
                       if(mount==pos)
                       {
                           addleft(p,ele);
                       }
                       p=p->next;
                   }
                   break;
            case 4:printf("Enter the element to be deleted:/n");
                   scanf("%d",&ele);
                   p=head;
                   while(p!=NULL)
                   {
                       if(p->data==ele)
                       {
                           delete(p);
                       }
                       p=p->next;
                   }
                   break;
                  
            case 5: display(head);
                   break;
            case 6:exit(0);
                   break;
            case 7: head=reverse(head);
                    break;
            case 8: sorting(head);
                   break;
            case 9:printf("Enter the number of nodes to be rotated \n");
                   scanf("%d",&n);
                   head=rotate(head,n);
                   break;
            case 10:exchange(head);
                   break;
            case 11: even(head);
                   break;
            case 12: head=odd(head);
                   break;
            case 13:printf("Number of elements in the second list :\n");
                    scanf("%d",&m);
                    for(i=0;i<m;i++)
                    {
                        printf("Enter the element:\n ");
                        scanf("%d",&ele);
                        head1=insertfront(head1,ele);
                    }
                    concatenate(head,head1);
                    break;
        }
    }

}