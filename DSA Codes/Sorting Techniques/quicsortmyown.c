//jenny
#include<stdio.h>
#include<stdlib.h>

void printArray(int A[],int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int A[],int lb, int ub)
{
    int pivot=A[lb];
    int start=lb;
    int end=ub;

    while(start<end)
    {
        while(A[start]<=pivot)        //when start becomes greater then we stop else stat++
        {
            start++;
        }
        while(A[end]>pivot)          //when end becomes smaller then we stop else end--
        {
            end--;
        }
        if(start<end)
        {
            swap(&A[start],&A[end]);
        }
    }
    swap(&A[lb],&A[end]);               //here dont perform swapping between the pivot and end... perfrom swapping between the A[lb] and A[end]....pivot is just variable assign to the A[lb]
    return end;                         //here we return the end because for the partition means we give index value to the quicksort function....and through these index LHS elements are smaller and RHS elements are greater means the Partition was Done
}

void quicksort(int A[],int lb,int ub)
{
    if(lb<ub)                           //when inside the array single element was remaining during the partition then lb and ub are pointing at the same location then these condition will false and come outside the loop
    {
        int loc=partition(A,lb,ub);                ///
        quicksort(A,lb,loc-1);
        quicksort(A,loc+1,ub);
    }
}


int main(){
    int A[]={50,45,14,5,78,32,14},n=7;
    printArray(A,7);

    quicksort(A,0,7);
    printArray(A,7);

    return 0;
}