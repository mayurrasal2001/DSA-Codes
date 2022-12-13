#include<iostream>
using namespace std;

int getsum(int n)
{
    if(n==0)
        return 0;
    return n+getsum(n-1);
}

int main(){
int n=5;

cout<< getsum(n);
return 0;
}