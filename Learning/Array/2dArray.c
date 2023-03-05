#include<stdio.h>

int main(){
    //  Declaration
    int a[3][2];

    //  Initialise (Without loop)
    int b[3][2] = {{1,2},{2,3},{3,4}};

    //  Access a single point(2)
    int temp = b[1][0];
    printf("%d",temp);
}