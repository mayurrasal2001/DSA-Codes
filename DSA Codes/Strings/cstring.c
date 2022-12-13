#include<stdio.h>
#include<string.h>

int main(){
    char str[]="geeksforgeeks";
    printf("%d ",strlen(str));
    str=str + "mayur";
    printf("%c ",str);
    printf("%c ",substr(1,3));
    printf("%d ",strfind("eek"));

return 0;
}