#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head;

void Create(int A[], int n)
{
    int i=0;
    struct Node *t, *last;
    Head=(struct Node *)malloc(sizeof(struct Node*));
    Head->data=A[0];
    Head->next=Head;                  //Head->next=Head Because this is the Circular Linked List
    last=Head;                        //For pointing to the newly created Nodes

    for(i=1; i<n; i++ )
    {
        t=(struct Node *)malloc(sizeof(struct Node *));
        t->data=A[i];
        t->next=last->next;           //t->next=last->next Because this is the Circular Linked List
        last->next=t;                //this is for the linking of first node and this newly created node
        last=t;                       //last is moving to the newly created node for linking to the next node
    }
}


void Display(struct Node *p)
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while((p!=Head));
    printf("\n");
}


void RDisplay(struct Node *p)
{
    static int flag=0;                   //Iniatially flag was 0
    if(p!=Head || flag==0)
    {
        flag=1;                        //After performing one comparison flag will one
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

int length(struct Node *p)
 {
     int len=0;
     do
     {
         len++;
         p=p->next;
     }while(p!=Head);
     return len;
 }


void Insert(struct Node *p, int index , int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > length(p))
        return;

    if(index==0)
    {
        if(Head==NULL)
        {
            Head=t;
            Head->next=Head;
        }

        else    
            while(p->next!=Head)
            {
                p=p->next;
            }
            t=(struct Node *)malloc(sizeof(struct Node*));
            t->data=x;
            p->next=t;
            t->next=Head;
            Head=t;
    }
    else
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node*));
        t->data=x;
        t->next=p->next;
        p->next=t;
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

    if(index<0 || index >length(p))
        return-1;

    if(index==1)
    {
        while(p->next!=Head)
        {
            p=p->next;
        }
        x=p->data;
        if(Head==p)                     //if there was only one node means only one node in the LL
        {
            free(Head);
            Head=NULL;
        }
        else 
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }

    else
    {
        for(i=0; i<index-2; i++)      //Here we take only ONE Moving pointer hence index-2 But in Linear LL we take 2 moving pointer therefore they take index-1
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}



int main(){
int A[]={2,4,6,8,11};
Create(A,5);

Delete(Head,5);
Display(Head);

// Insert(Head,5,55);
// Display(Head);


// Display(Head);
// RDisplay(Head);


return 0;
}