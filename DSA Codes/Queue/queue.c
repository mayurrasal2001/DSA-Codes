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
    q->front=q->rear=-1;   //means initially front and rear is pointing to the -1 
    q->Q=(int *)malloc(q->size*sizeof(int));    //if we give size as input then it will take the size of array
}

//malloc function create an array Q where q is pointing
void enqueue(struct queue *q, int x)
{
    if(q->rear==q->size-1)
        printf("Queue is Full");
    else
        q->rear++;
        q->Q[q->rear]=x;            //take out the value in x
}

int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)                    //when front and rear are pointing to the same location 
        printf("queue is Empty");
    else   
    {
        q->front++;
        x=q->Q[q->front];                    //taking the value inside the x form the array Q where the front is pointed
    } 
    return x;      
}

void Display(struct queue q)
{
    int i;
    for(i=q.front+1; i<=q.rear; i++)        //front+1 because initially front is pointing to the -1
    {
        printf("%d ", q.Q[i]);              // showing storing elements in the Q[Array]
    }
    printf("\n");
}


int main(){
    struct queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    dequeue(&q);
    Display(q);

    printf("%d ", dequeue(&q));

    return 0;
}
