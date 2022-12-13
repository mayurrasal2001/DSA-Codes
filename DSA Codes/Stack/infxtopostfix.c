#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;                             


void push(char x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));        

    if(t==NULL)                                     
        printf("Stack is Full");
    else    
    {
        t->data=x;
        t->next=top;
        top=t;
    }
    
}


char pop()
{
    struct Node *t;                   
    char x=-1;
    if(top==NULL)                                          
        printf("Stack is Empty");
    else
    {
        t=top;                           
        top=top->next;             
        x=t->data;             
        free(t);       
    }
        return x;
    
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
        {                      
            if(top==NULL)    
                return 0;     
            pop();
        }
    }
    if(top==NULL)
        return 1;
    else 
        return 0;         
}

char pre(char x)                //function precedence
{
    if(x=='+' || x=='-')
        return 1;              //return 1 because  + and - have same precedence i.e 1  
    else if(x=='*' || x=='/')
            return 2;          //because precedence are more than the + and -
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;                                  //return false because it is operand if there is operator then it will return true
    else 
        return 1;
}

char * infxTopost( char *infix)         //character pointer of type infix as parameter 
{
    int i=0, j=0;                      //iniatialise to 0
    char *postfix;
    int len=strlen(infix);           //getting length of the infix expression and stored into the len variable
    postfix=(char *)malloc((len+2)*sizeof(char));      //craeting the array in Haap i.e Allocating the memory in heap and multiply by the size of in

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))     //checking that this is operand or not by passing the infix
            postfix[j++]=infix[i++];   //if isoperand function returns true then add it to the postfix expressions
        else
        {
            if(pre(infix[i]) > pre(top->data))   //if precedence of the infix is greater than the stacktop precence then push it into the stack
                push(infix[i++]);
            else                                 //if precedence of the infix is smaller than the stacktop precedence then pop out it and send(store) to the postfix expression
                {
                    postfix[j++]=pop();
                }
        }
    }
    while(top!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';        //at the end of the postfix we add the null character so make it complete
    return postfix;
}

int main(){
    char *infix="a+b*c-d/e";
    
    push('#');  //because initially no any data in the stack

    char *postfix=infxTopost(infix);
    printf("%s ", postfix);
    return 0;
}


//for the practice purpose

// while(infix[i]!='\0')
// {
//     if(isOperand(infix[i]))
//         postfix[j++]=infix[i++]
//     else
//         if(pre(infix[i]) > pre(top->data))
//             push(infix[i++])
//         else   
//             postfix[j++]=pop();
// }