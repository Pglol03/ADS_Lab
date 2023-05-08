#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int pivotpos = (low-1);
    
    for(int j = low ; j<=high-1 ; j++){
        if(arr[j]<pivot){
            pivotpos++;
            swap(&arr[pivotpos], &arr[j]);
        }
    }
    swap(&arr[pivotpos+1],&arr[high]);
    return (pivotpos+1);
}

void quickSort(int arr[], int low, int high){
    if(low<high){
    int pivotpos = partition(arr,low,high);
    quickSort(arr,low,pivotpos-1);
    quickSort(arr,pivotpos+1,high);
}
}

int main(){
     int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);

    printf("Sorted Array : \n");

    for(int i = 0 ; i<size ; i++){printf("%d ",arr[i]);}
    printf("\n");
    return 0;
}