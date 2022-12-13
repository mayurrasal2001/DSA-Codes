#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p, *q;                            //declaring the pointers

    int i;                                //initialise the i

    p=(int *)malloc(5*sizeof(int));      //creating the array of size by using the pointer p
    p[0]=2;p[1]=4;p[2]=6;p[3]=8;p[4]=10; //initialise array

    q=(int *) malloc(10*sizeof(int));   //creating large size array because array cannot be resized
    for(i=0; i<5; i++)
    q[i]=p[i];                          //Copying the Data array p in array q

    free (p);                           //free the memory of the previous array
    p=q;                                //pointing p to q
    q=NULL;                             //q get null now newly resized array name is p

    for(i=0;i<5;i++)
        printf("%d ",p[i]);

    return 0;
}