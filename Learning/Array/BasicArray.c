#include<stdio.h>

//  Declaration
int a[6];
double b[5];

//  Static Initialisation
int days[] = {31,28,30,31,30};

//  Dyanamic Initialisation
int c[6];

int main(){
    //  Runtime Initialisation
    int d[5];
    for(int i = 0; i<5;i++){
        d[i] = 5-i;
    }

    //  Read an Element
    int temp = d[2];

    //  Write to an array element
    d[3] = 6;

    //  Strings is C
    char e[] = "Hello World";
    char *f = "Hello World New";

    printf("%s", e);
    printf("%s", f);

} 
