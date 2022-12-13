#include<iostream>
using namespace std;
int main(){

    string str="geeksforgeeks";
    for(int i=0; i<str.length(); i++)
        cout<<str[i];
    cout<<endl;

    //by using the small method
    for(char x:str)
    cout<<x;
return 0;
}