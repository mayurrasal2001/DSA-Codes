#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;         //pointer Q for an array   || Pointer of interger Array
};

void create(struct queue *q, int size)
{
    q->size=size;         //q->size is the input that we give through the input
    q->front=q->rear=0;   //because always front remains empty for avoiding the isEmpty condition
    q->Q=(int *)malloc(q->size*sizeof(int));    //if we give size as input then it will take the size of array
}

void enqueue(struct queue *q, int x)
{
    if((q->rear+1)%q->size==q->front)   //i.e= rear=(rear+1)%size   here only rear is moving for insertion
        printf("Queue is full");
    else 
    {
        q->rear=(q->rear+1)%q->size;      //formula----->rear=(rear+1)%size
        q->Q[q->rear]=x;
    }   
}

int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is Empty");
    else 
    {
        q->front=(q->front+1)%q->size;        //here the only from will move forward for deletion
        x=q->Q[q->front];                     //Assign value to the x
    }   
    return x;    
}

void Display(struct queue q)
{
    int i=q.front+1;           //means start traversing from the 0th position not from the -1
    
    do
    {
        printf("%d ", q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);      //terminating condition means here i is moving from front+1 to the rear-1 position it traversing all of the Queue

    printf("\n");
}


int main(){
    struct queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    


    Display(q);
    printf("%d ", dequeue(&q));

    
    return 0;
}
