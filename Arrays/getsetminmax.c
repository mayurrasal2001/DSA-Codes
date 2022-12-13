#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int Length;
    int size;
};

void Display(struct Array arr)
{
    for(int i=0;i<arr.Length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}
//get means find a element of the particular position
int get(struct Array arr, int index)
{
    if(index>0 && index<=arr.Length)
        return arr.A[index];
    return -1;
}

// set means replace the element od the particular position

int set(struct Array *arr,int index,int x)
{
    if(index>0 && index<=arr->Length)
        return arr->A[index]=x;
    return -1;
    printf("\n");
}

int max(struct Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=1; i<arr.Length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int min(struct Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=1; i<arr.Length; i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
        return min;
    }
}

int sum(struct Array arr)
{
    int s=0;
    int i;
    for(i=0; i<arr.Length;i++)
    {
        s=s+arr.A[i];
    }
    return s;
}

float Avg(struct Array arr)
{
    return (float)sum(arr)/arr.Length;
}

int main(){
    struct Array arr={{25,45,78,96,78,32,91},7,7};
    // printf("%d ",get(arr,3));
    // printf("%d",set(&arr,4,334));
    // printf("%d",max(arr));
    // printf("%d",min(arr));
    // printf("%d",sum(arr));
    printf("%f",Avg(arr));
    

    printf("\n");
    Display(arr);

return 0;
}