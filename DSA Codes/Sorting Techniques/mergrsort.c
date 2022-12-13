#include<stdio.h>


void printArray(int A[],int n)
{
    for(int i=0; i<n;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[],int lb, int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[10]={};

    while(i<=mid && j<=ub)
    {
        if(A[i]<=A[j])
        {
            b[k]=A[i];
            i++;
        }
        else
        {
            b[k]=A[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=ub)             //means j's elment are remaining but i is finish
        {
            b[k]=A[j];
            j++;
            k++;
        }
    }
    else                 //else(j>ub)
    {
        while(i<=mid)
        {
            b[k]=A[i];
            i++;
            k++;
        }
    }
    for(int k=lb; k<=ub; k++)
    {
        A[k]=b[k];
    }

}


void mergesort(int A[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
}


int main(){
    int A[]={50,25,41,46,78,14,36,25,78,96}, n=10;
    printArray(A,10);
    mergesort(A,0,n-1);
    printArray(A,10);

return 0;
}