#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Display(struct Array arr)
{
    for(int i=0; i<arr.length; i++)
    {
        printf("\n%d ",arr.A[i]);
    }
    
}

int LinearSearch(struct Array *arr,int key)
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;            
        }
        
    }
    return -1;
}


int main(){
    struct Array arr={{45,65,98,74,25,55,47}, 10,7};
    printf("%d ",LinearSearch(&arr,55));
    Display(arr);

return 0;
}