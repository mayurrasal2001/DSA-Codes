#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int Length;
};

void Display(struct Array arr)
{
    for(int i=0; i<arr.Length;i++)
    {
        printf("%d ", arr.A[i]);
    }
}

void insert(struct Array *arr, int x)
{
    int i=arr->Length-1;
    if(arr->Length==arr->size)         //means check that size is remaining in array or not for the shifting
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];         //these loop is for shifting the elements
        i--;
    }
    arr->A[i+1]=x;  //here uppar condition does not enter into the while because now A[i]<x then directly comes here
    arr->Length++;
}

int issorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.Length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;          //Array is not sorted    
    }
    return 1;                  //Array is sorted 
}

int main(){
    struct Array arr={{25,27,28,29,32,33,35},10,7};
    // insert(&arr,30);
    printf("%d ",issorted(arr));
    // Display(arr);


return 0;
}