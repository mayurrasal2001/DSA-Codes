#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionSort(int A[], int n)
{
    int i,j,k;
    for(i=0; i<n-1; i++)
    {
        k=i;                     //here we take the extra variable k because of we can't take i because we find the mininum index, and at outside the inner for loop we swap A[i] with A[k]
        for(j=i+1; j<n; j++)
        {
            if(A[k]>A[j])       //Initially k is at the position of i then it will check the condition ifA[k]>A[j] if condition will true then k will move to the j and then j will Increment
                k=j;
        }
        Swap(&A[i], &A[k]);     //when j reaches at the n i.e j<n the it will terminates the loop and swapping may perform with A[i]with A[k]
    }
}

int main()
{
    int A[]={50,45,14,36,87}, n=5,i;
    selectionSort(A,5);

    for(i=0;i<n; i++)
        printf("%d ",A[i]);
    return 0;
}

 


