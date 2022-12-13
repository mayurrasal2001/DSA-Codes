#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    
    if(t==NULL)                        //if we are unable to create the new node  means heap is full
        printf("Queue is Full\n");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)              //if this is the first Node
            front=rear=t;
        else 
        {
            rear->next=t;       //at any other position
            rear=t;
        }                         
    }
        
}

int deque()
{
    int x=-1;
    struct Node *t;

    if(front==NULL)
        printf("Queue is Empty");
    else
    {
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;    
}

void Display()
{
    struct Node *p=front;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    Display();

    printf("%d ", deque());
    return 0;
}