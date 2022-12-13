//ALL THE OPERATIONS INSIDE THE STACK TAKE THE CONSTANT TIME FOR THE EXECUTION i.e O(1)

#include<stdio.h>
#include<stdlib.h>

struct Stack       //Defining the structure of Stack 
{
    int size;
    int top;
    int *S;       //Array Name
};

void Create(struct Stack *st)   //parameter as a structure stack and pointer st call by reference
{
    printf("Enter the size ");
    scanf("%d", &st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));  //creating array Dynamically in Heap 
}
void Display(struct Stack st)   //here it only the call by value because here we can't modify the stack only Display
{
    int i;
    for(i=st.top;i>=0;i--)       //here i can start from i and i>=0 means here we display elements in the Vertical manner means recently inserted elements
        printf("%d ", st.S[i]);  //printing the array
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if(st->top==st->size-1)         //checking stack is full or not
        printf("Stack Overflow \n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)                       //checking stack is Empty or not
        printf("Stack Underflow \n");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)      //finding top            //top=size-1;
{                                                                  //top=5-1
    int x=-1;                                                       //top=4
    if(st.top-index+1<0)                                            //S[top-index+1]
        printf("Invalid Index");                                    //S[4-3+1]
    else                                                            //S[2]
        x=st.S[st.top-index+1];
    return x;
}

int isFull(struct Stack st)
{
    if(st.top==st.size-1)
        return 1;         //return true
    else
        return 0;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    else   
        return 0;
}



int main(){
    struct Stack st;
    Create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));
    printf("%d \n",pop(&st));

    //printf("%d \n", peek(st,3));

    // printf("%d \n", isFull(st));
    // printf("%d \n", isEmpty(st));
    // printf("%d \n", isTop(st));

    Display(st);

 
    return 0;
}