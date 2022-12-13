#include<iostream>
#include<string.h>
using namespace std;

int nonRep(string &str)
{
    for(int i=0;i<str.length();i++)
    {
        bool flag=false;
        for(int j=0;j<str.length();j++)
        {
            if(i!=j && str[i]==str[j])     //i!=j means this condition  is for the first element at first time condition will false and then j will increment to next and then condition will true
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            return i;
        
    }
    return -1;

}
int main(){
    string str="abcdabc";
    cout<<nonRep(str);

return 0;
}