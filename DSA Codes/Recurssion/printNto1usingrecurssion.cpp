#include<iostream>
using namespace std;

int printNto1(int n)
{
    if(n==0)
    return 0;
    cout<<n<<" ";
    printNto1(n-1);
}
    

int main()
{
    int n=100;
    cout<<printNto1(n);
    return 0;
}