#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=first->prev=NULL;                  //Because it is Doubly Linked List
    last=first;                                    //last will Pointing to the first

    for(i=1; i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;                           //linking betweeen two nodes
        t->prev=last;                                 //Doubly
        last->next=t;                                 //last will move to next node
        last=t;
    }
}
int length(struct Node *p)
{
    int l=0;

    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}


void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void Insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *t;

    if(index<0 || index > length(p))
        return ;
    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }

    else
        {
            for(i=0; i<index-1; i++)
            {
                p=p->next;
            }
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->prev=p;
            t->next=p->next;
            if(p->next!=NULL)p->next->prev=t;
            p->next=t;

        }
}

int Delete(struct Node *p, int index)
{
    int i,x=-1;
    if(index < 1 || index > length(p))
        return -1;

    if(index==1)
    {
        first=first->next;
        if(first!=NULL)
            first->prev=NULL;//
        x=p->data;
        free(p);
    }

    else
    {  
        for(i=0; i<index-1; i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;          //forward Linking
        if(p->next!=NULL)               //means identify that after p was any node or not
            p->next->prev=p->prev;     //Backward Linking
        x=p->data;
        free(p);
    }
    return x;
}

//Not Fully Understanding Operation
void Reverse(struct Node *p)
{
    struct Node *temp;

    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}

int main(){
int A[]={12,14,16,17,88,65};
Create(A,6);


Reverse(first);
Display(first);

// Delete(first,5);
// Display(first);


// Insert(first,4,33);
// Display(first);

// printf("\nLength of the Linked List is %d \n", length(first));
// Display(first);

return 0;
}