#include<stdio.h>
#include<stdlib.h>

void insertionSort(int A[], int n)
{
    int i,j, x;
    for(i=1; i<n; i++)
    {
        x=A[i];
        j=i-1;
        while(j>=0 && A[j]>x)
        {
            A[j+1]=A[j];            //by using arr[j+1] here it override only not swap 
            j--;
        }
        A[j+1]=x;
    }
}
int main(){
    int A[]={50,20,14,12,32,887,74,25},n=8,i;
    insertionSort(A, 8);

    for(i=0; i<8; i++)
        printf("%d ", A[i]);

return 0;
}