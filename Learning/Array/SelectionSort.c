#include<stdio.h>
void InsertionSort(int arr[], int size);

int main(){
    int s;
    printf("Enter the size of the array\n");
    scanf("%d",&s);

    int a[s];

    for(int i = 0 ; i<s ; i++){
        printf("Enter array element :\n");
        scanf("%d",&a[i]);
    }

    InsertionSort(a,s);
    printf("Sorted Array is :\n");
    for(int i = 0; i<s;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void InsertionSort(int arr[], int size){
    int smallest;
    for(int i = 0; i<size; i++){
        smallest = arr[i];
        for(int j=i+1; j<size ; j++){
            if(arr[i] > arr[j]){
                smallest = arr[j];
                arr[j] = arr[i];
                arr[i] = smallest;
            }
        }
    }
}