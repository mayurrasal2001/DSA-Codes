#include<stdio.h>
#include<stdlib.h>
void printArray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void shellSort(int A[],int n)
{
    int i,j,gap,temp;

    for(gap=n/2; gap>=1;gap/=2)
    {
        for(i=gap; i<n; i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];         //here the sawpping was done means A[j+gap] are override the A[j]
                j=j-gap;                //and then j will --
            }
            A[j+gap]=temp;              //then again we find the new temp
        }
    }
}
int main(){
int A[]={25,45,14,56,87,96,48},n=7;
printArray(A,n);

shellSort(A,n);
printArray(A,n);

return 0;
}