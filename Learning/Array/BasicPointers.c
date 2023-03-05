#include<stdio.h>

//  Declaration
int *p;

int main(){
    int i = 4;
    //  Assigning Address using '&' sign
    p = &i;
    i = 5;
    printf("%d", i);
    printf("%d", p);
    
    //  Pointers and Arrays
    char a[] = "Hello World";
    char *pa = &a[0];
    printf("%s",a);
    printf("%s",pa);
}