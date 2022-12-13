#include<stdio.h>
#include<string.h>

int main(){                                        //a
char s1[]="bcd";                                   //aa
char s2[]="abc";                                   //aaa.....
                                                   //ab
                                                   //ac
int res=strcmp(s1,s2);
    if(res>0)
        printf("s1 is greater than s2");
    else if(res==0)
        printf("s1 and s2 are same");
    else
        printf("s1 is smaller and s2 is greater");

    return 0;
}