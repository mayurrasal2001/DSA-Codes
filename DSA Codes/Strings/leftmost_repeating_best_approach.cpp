#include<iostream>
using namespace std;

const int CHAR=256;
int leftmost(string str)
{
    int count[CHAR]={0};
    for(int i=0;i<str.length();i++)
    {
        count[str[i]]++;
    }

    for(int i=0;i<str.length();i++)
    {
        if(count[str[i]]>1)
            return i;
    }
    return -1;
}
int main(){
    string str="wxzcabcad";                  //here the count of the c is greater than 1
    string str1="wxzcvbnm";                  //here no any matching characters
    cout<<leftmost(str);


return 0;
}