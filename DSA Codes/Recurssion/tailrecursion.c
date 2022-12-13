#include<stdio.h>

void Display(int n)
{
    if(n==0)
        return 0;
    else
        printf("%d \n",n);
        Display(n-1);
}
int main(){
    Display(10);
}


// #include<stdio.h>

// void Display(int n)
// {
//     if(n==0)
//         return 0;
//     else
//         Display(n-1);
//         printf("%d \n",n);
// }
// int main(){
//     Display(10);
// return 0;
// }