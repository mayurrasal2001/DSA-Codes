#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int Length;
};

void Display(struct Array arr)
{
    for(int i=0;i<arr.Length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

struct Array* merge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=0;
    j=0;
    k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->Length && j<arr2->Length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];

    }
    for( ; i<arr1->Length;i++)
        arr3->A[k++]=arr1->A[i];
    for( ; j<arr2->Length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->Length=arr1->Length+arr2->Length;
    arr3->size=14;
    return arr3;
}

int main(){
    struct Array arr1={{12,14,16,18,19,21,22}, 10,7};
    struct Array arr2={{13,15,17,20,23,24,28,58}, 10,8};
    struct Array *arr3;

    arr3=merge(&arr1,&arr2);
    Display(*arr3);
   




return 0;
}