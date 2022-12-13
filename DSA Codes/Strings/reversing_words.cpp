#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void reverse (char str[],int low,int high)
{
    while(low<=high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

void reversewords(char str[],int n)
{
    int start=0;
    for(int end=0; end<n;end++)
    {
        if(str[end]==' ')
        {
            reverse(str,start,end-1);
            start=end+1;
        }
            
    }
    reverse(str,start,n-1);      //these is for the reverse the last word
    reverse(str,0,n-1);          //for reversing the whole string
    cout<<str;
}
int main(){
    char str[]="welcome to Gfg";
    cout<<str<<endl;

    
    
    reversewords(str,14);

return 0;
}