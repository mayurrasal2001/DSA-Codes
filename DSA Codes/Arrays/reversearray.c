#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int Length;
    int size;
};

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Display(struct Array arr)
{
    for(int i=0;i<arr.Length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

//Inside these function just copying the elements from first array to the 2nd Array then again 2nd to first
void reverseArray(struct Array *arr)
{
    int i,j;
    int *B;
    B=(int *)malloc(arr->Length*sizeof(int));
    for(i=arr->Length-1,j=0;i>=0; i--,j++)     //these for loop is for the copying the elements from the first Array from backside to the second Auxillary Array
    {
        B[j]=arr->A[i];
    }
    for(i=0; i<arr->Length;i++)           //these for loop is for the copying the elements from the second array to the first Array
    {
        arr->A[i]=B[i];
    }
}

//inside these function swapping of the elements are done
void reverseArray2(struct Array *arr)
{
    int i,j;
    for(int i=0,j=arr->Length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

int main(){
    struct Array arr={{12,13,14,15,16,17,18}, 7,7};
    // reverseArray(&arr);
    reverseArray2(&arr);
    Display(arr);

return 0;
}