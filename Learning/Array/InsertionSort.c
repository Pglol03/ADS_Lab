#include<stdio.h>

int main(){
    printf("Enter the size of the array\n");
    int s;
    scanf("%d",&s);
    int a[s];
    for(int i = 0; i<s ; i++){
        printf("Enter array element\n");
        scanf("%d",&a[i]);
    }
    InsertionSort(&a,s);
    printf("Result is \n");
    for(int i = 0; i<s;i++){
        printf("%d",a[i]);
    }
    return 0;
}

void InsertionSort(int* arr, int size){
    int i, j, key;
    for(j = 1 ; j<size ; j++){
        key = arr[j];
        i = j-1;
        while(i>0 && arr[i]>key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}