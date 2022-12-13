#include<iostream>
#include<string.h>
using namespace std;

const int CHAR =256;
bool Anagram(string s1, string s2)
{
    if(s1.length()!=s2.length())
        return false;               //means check that all characters of the s1 are in s2 or not ,means check the length of the both string
    int count[CHAR]={0};            //here the all 256 characters assign 0 to all characters 
    for(int i=0; i<s1.length();i++)
    {
        count[s1[i]]++;                  //s1 will++
        count[s2[i]]--;                  //s2 will--
    }
    for(int i=0; i<CHAR; i++)        //here these loop will traverse upto the all 256 characters if loop will found the count value which is greater than the 0 then it is false and if they are all are o the condition will true
    {
        if(count[i]!=0)
            return false;
    }
    return true;                    //means all are 0 means all values of the s1 are in s2
}
    int main(){
    string s1="aaabc";
    string s2="aabac";
    cout<<Anagram(s1,s2);


    return 0;
}