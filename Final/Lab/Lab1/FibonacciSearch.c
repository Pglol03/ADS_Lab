#include<stdio.h>
#include<stdlib.h>

int min(int a, int b) { return (a<=b ? a:b); }

int fibonacciSearch(int arr[], int key, int len){
    int fib0, fib1, fib;
    fib0 = 0;
    fib1 = 1;
    fib = fib0 + fib1;

    while(fib<len){
        fib0 = fib1;
        fib1 = fib;
        fib = fib0 + fib1;
    }

    int partitionI = -1;

    while(fib>1){
        int i = min(partitionI + fib0, len-1);

        if(arr[i]<key){ //key is greater, second part of the array(fib1)
            partitionI = i;
            fib = fib1;
            fib1 = fib0;
            fib0 = fib - fib1;
        }
        else if(arr[i]>key){    //  key is smaller, first part of the array(fib0)
            fib = fib0;
            fib1 = fib1-fib0;
            fib0 = fib-fib1;
        }
        else { return i; }
    }
    return -1;
}

int main(){
    int arr[] = { 1,5,7,8,9,10 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int search = 7;

    int find = fibonacciSearch(arr,search,size-1);
    printf("%d found at loc %d.\n",search,find+1);
    return 0;
}