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

int findmax(int A[], int n)
{   int i;
    int max=0;
    if(A[i]>max)
    {
        max=A[i];
    }
    return max;
}
void countSort(int A[],int n)
{
    int i,j,max,*C;
    max=findmax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));

   for(i=0;i<max+1;i++) 
   {
       C[i]=0;
   }

   for(i=0;i<n;i++)
   {
       C[A[i]]++;
   }

   i=0;
   j=0;
   while(j<max+1)
   {
       if(C[j]>0)
       {
           A[i++]=j;
           C[j]--;
       }
       else
       {
           j++;
       }
   }
}

int main(){
    int A[]={50,45,7,8,32,14,85,45,69},n=9;
    printArray(A,9);

    countSort(A,9);
    printArray(A,9);

return 0;
}