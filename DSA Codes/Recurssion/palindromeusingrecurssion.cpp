#include<iostream>
using namespace std;

//initially start=0 and end= n-1
bool ispalindrome(string &str, int start, int end)
{
    if(start>=end)
    return true;

    return (str[start]==str[end])&&
    ispalindrome(str, start+1, end-1);
}
int main(){
    str="abcba";
    ispalindrome(str);
    return 0;
}