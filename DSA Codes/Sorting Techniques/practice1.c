#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
    int temp= *x;
    *x = *y;
    *y = temp;
}

void Bubble(int A[],int n)
{
    int i,j,flag=0;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[]={100,8,5,2,7,6,9},n=7,i;
    Bubble(A,n);

    for(i=0;i<7;i++)
        printf("%d ",A[i]);
    return 0;
}


