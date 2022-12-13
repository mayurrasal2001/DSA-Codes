//Baari
#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y)
{
    int temp= *x;              
    *x= *y;
    *y=temp;
}

void selection(int A[], int n)
{
    int i,j, flag=0;
    for(i=0; i<n-1; i++)              //this loop is only for the paasses
    {
        flag=0;
        for(j=0;j<n-i-1;j++)       //this loop is for the comparisons
        {
            if(A[j] > A[j+1])        //for swapping..if these condition will true then only the swapping was done
            {
                Swap(&A[j], &A[j+1]);
                flag=1;              //flag=1 means the swappig was done
            }      
        }
        if(flag==0)                  //means after the last pass after all elements are in sorted manner and then only flag remains 0 means it doesnot true inside in the inner for loop it remains false 
            break;
    }
}
int main()
{
    int A[]={100,8,5,2,7,6,9},n=6,i;
    selection(A,n);

    for(i=0;i<6;i++)
        printf("%d ",A[i]);
    return 0;
}