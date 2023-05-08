#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int arr[],int len){
   

    for(int i = 0; i<len ; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(&arr[j-1],&arr[j]);
            j--;
        }
    }
}

int main(){
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);
     printf("Sorted Array : \n");

    for(int i = 0 ; i<size ; i++){printf("%d ",arr[i]);}
    printf("\n");
}