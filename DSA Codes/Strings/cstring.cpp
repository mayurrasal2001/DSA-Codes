#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string str="geeksforgeeks";
    cout<<str.length()<<" "<<endl;
    str=str + "mayur";
    cout<<str<<" ";
    cout<<endl;
    cout<<str.substr(1,3)<<endl;
    cout<<str.find("eek");
  
    return 0;
    }



   