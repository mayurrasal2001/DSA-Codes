#include<iostream>
using namespace std;
int main(){
    string str;
    cout<<"Enter your Name ";
    //cin>>str;                     //by using the cin compiler take only input of the one text when we remain space between then it will ignore it..ex.cin<<Mayur Rasal.....output is Mayur only
    getline(cin,str);               //by using the getline function it will take all content but cin will take only before the space      
    cout<<"Your Name is "<<str;


    return 0;
}