#include <iostream>
using namespace std;

// void fun1(){
//     cout<<"Fun1() \n";
// }

// void fun2(){
//     cout<<"Fun 2 is called \n";
//     cout<<"Inside the fun 2 \n";
//     fun1();   //calling function inside the function is called the Recurrsion
// }


// int main(){
//     cout<<"Before fun1()\n";
//     fun2();
//     cout<<"After fun2()\n";
// }

// Terminating condition for the never stopped recursive problem

void fun2(int n){
    if(n==0)
    return ;
    cout<<"fun2 is called "<<endl;
    fun2(n-1);
}

int main(){
    fun2(10);
}