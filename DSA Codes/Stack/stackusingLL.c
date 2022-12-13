#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;                              //initially top is Null


void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));               //Dynamically create Node at left side

    if(t==NULL)                                     //if we are unable to create the node i.e Heap is full
        printf("Stack is Full");
    else    
    {
        t->data=x;
        t->next=top;
        top=t;
    }
    //printf("\n");
}


int pop()
{
    struct Node *t;                   //Creating the temporary pointer
    int x=-1;
    if(top==NULL)                                          //confirm that Stack is Empty or not means conclude that top will pointing to the -1 or not
        printf("Stack is Empty");
    else
    {
        t=top;                      //and this created temporary pointer pointing to the top           
        top=top->next;              //top move to next node
        x=t->data;                  //assign data to x;
        free(t);                    //Delete t;
    }
        return x;
    //printf("\n");
}


void Display()
{
    struct Node *p;
    top=p;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}


int main(){

    push(10);
    push(20);
    push(30);
    push(40);

    Display();

    printf("Deleted element are %d", pop());

    return 0;
}