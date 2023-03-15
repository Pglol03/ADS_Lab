#include<stdio.h>

void Swap(int arr[], int i, int j);
int Partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);

int main(){
    int s;
    printf("Enter the size of the array :\n");
    scanf("%d",&s);

    int a[s];

    for(int i = 0; i<s ; i++){
        printf("Enter Array Elements :\n");
        scanf("%d",&a[i]);
    }

    QuickSort(a, 0, s-1);
    
    printf("Sorted Array :\n");
    for(int i = 0 ; i<s ; i ++){
        printf("%d ",a[i]);
    }
}

void Swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {

            // If current element is smaller
            // than the pivot
            if (arr[j] < pivot) {

                // Increment index of
                // smaller element
                i++;
                Swap(arr, i, j);
            }
        }
        Swap(arr, i + 1, high);
        return (i + 1);
}

void QuickSort(int arr[], int low , int high){
    if (low < high) {
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = Partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}