#include<iostream>
using namespace std;
 bool issubseq(string s1,string s2,int m,int n)
    {
        int j=0;
        for(int i=0; i<n && j<m;i++)
        {
            if(s1[i]==s2[j])
                j++;
        }
        return(j==m);
    }
int main(){
    string s1="ABCDEFGH";
    string s2="HGF";
    cout<<issubseq(s1,s2,7,3);
   

return 0;
}