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
    for(int i=0; i<arr.Length;i++)
    {
        printf("\n%d ",arr.A[i]);
    }
    printf("\n");
}

int BinarySearch(struct Array arr, int key)
{
    int l,h,mid;
    int i=0;
    h=arr.Length-1;

    while(i<=h)
    {
        mid=(l+h/2);
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int main(){
    struct Array arr={{18,45,65,66,67,68,75,77,82,84,88},15,15};
    printf("%d ",BinarySearch(arr,67));
    Display(arr);

return 0;
}