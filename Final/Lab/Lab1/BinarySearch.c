#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int key, int low, int high){
    int mid;
    while(low!=high){
        mid = (low + high)/2;
        if(arr[mid]==key) {return mid;}
        else if (arr[mid]<key) {low = mid+1;}
        else {low = mid-1;}
    }
    return -1;
}

int main(){
    int arr[] = { 1,5,7,8,9,10 };
    int size = sizeof(arr)/sizeof(arr[0]);
    int search = 7;

    int find = binarySearch(arr,search,0,size-1);
    printf("%d found at loc %d.\n",search,find+1);
    return 0;
}