#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;                              //initially top is Null


void push(char x)
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


char pop()
{
    struct Node *t;                   //Creating the temporary pointer
    char x=-1;
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

int isBalanced(char *exp)
{
    int i;
    for(i=0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')')
        {                      //this is special condition for the parenthesis ')'....means there is only closing bracket in the stack.....but before there is no opening bracket
            if(top==NULL)     //means check that stack is empty or not and if stack is empty then condition will false and parenthesis are not maching hence return 0
                return 0;     //means return false
            pop();
        }
    }
    if(top==NULL)
        return 1;           // means if there nothing in the stack i.e parenthesis are matching i.e Balanced
    else 
        return 0;           //and if any parenthesis are remain in the stack i.e parenthesis are not match and it is unbalanced
}

int main(){
    //3 Conditions
    char *exp="((a+b)*(c-d))";   //this we will passing to the function
    // char *exp="(((a+b)*(c-d))";
    // char *exp="(((a+b)*(c-d)))";

    printf("%d ", isBalanced(exp));
    return 0;
}




