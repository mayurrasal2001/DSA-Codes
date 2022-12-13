#include<iostream>
#include<string.h>
using namespace std;

int main(){
string str="geeksforgeeks";
int count[26]={0};

for(int i=0; i<str.length();i++)
{
    count[str[i]-'a']++;
}

for(int i=0; i<26;i++)
{
    if(count[i]>0)
    {
        cout<<(char)(i+'a')<<" ";
        cout<<count[i]<<endl;
    }
}

return 0;
}


//Using C
// int main()
// {
// char str[]="geeksforgeeks";
// int count[26]={0};

// for(int i=0; i<strlen(str);i++)
// {
//     count[str[i]-'a']++;
// }

// for(int i=0; i<26;i++)
// {
//     if(count[i]>0)
//     {
//         printf("%c ",(char)(i+'a'));
//         printf("%d ",count[i]);
//         printf("\n");
//     }
// }
//     return 0;
// }
