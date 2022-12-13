#include<stdio.h>
#include<stdlib.h>


int main(){
    int A[5]={2,4,6,8,10};   //memory create in the Stack frame
    int *p;
    int i ;


    p=(int *)malloc(5*sizeof(int));  //memory create in the heap section because by using the pointer
    p[0]=12;
    p[1]=14;
    p[2]=16;
    p[3]=18;
    p[4]=20;

    for(i=0; i<5;i++)
        printf("%d ",A[i]);

    printf("\n");

    for(i=0; i<=5;i++)
        printf("%d ",p[i]);
    return 0;
}