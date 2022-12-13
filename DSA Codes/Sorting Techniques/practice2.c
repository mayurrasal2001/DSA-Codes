#include<stdio.h>
#include<stdlib.h>

void swap(int *x , int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertion(int A[],int n)
{
    int i,j,x;
    for(i=0;i<n-1;i++)
    {
        j = i-1;
        x=A[i];

        while(j >=0 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=x;
    }
}
int main(){
    int A[]={13,25,48,2,14,47},n=6;

    insertion(A,27);
    for(int i=0;i<6;i++)
    {
        printf("%d ",A[i]);
    }

return 0;
}