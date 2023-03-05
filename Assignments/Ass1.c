#include<stdio.h>
int menu(){
    int choice;
    printf("--------Menu--------\n1.  Bubble Sort\n2.  Insertion Sort\n3.  Merge Sort\n4.  Binary Search\n5.  Exit\n\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    return choice;
}

void bubble_sort(int size, int arr[]){
    if (size ==1){
        for( int i =0; i<size;i++){
            printf("%d\t", arr[i]);
        }
    }
    else{
        for(int i =0; i<size; i++){
            for(int j = 1; j< (size-i); j++){
                if(arr[j-1] > arr[j]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printf("The Array is Sorted By the bubble sort Algorithm \n");
        for( int i =0; i<size;i++){
            printf("%d\t", arr[i]);
        }
    }
}
void Bubble_sort(int size, int arr[]){
    if (size ==1){
        for( int i =0; i<size;i++){
            printf("%d\t", arr[i]);
        }
    }
    else{
        for(int i =0; i<size; i++){
            for(int j = 1; j< (size-i); j++){
                if(arr[j-1] > arr[j]){
                    int temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                }
            }
        }

    }
}
void insertion_sort(int size, int arr[]){
    for(int i = 0; i<size-1; i++){
        for( int j= i+1; j>0; j--){
             if(arr[j-1] > arr[j]){
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nThe Array is Sorted By the Insertion sort Algorithm \n");
        for( int i =0; i<size;i++){
            printf("%d\t", arr[i]);
        }
}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void Merge_sort(int arr[], int l, int r, int size){
        if (l < r) {
        int m = l + (r - l) / 2;

        Merge_sort(arr, l, m, size);
        Merge_sort(arr, m + 1, r, size);

        merge(arr, l, m, r);
    }


}
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        } else {
            return binarySearch(arr, mid + 1, r, x);
        }
    }

    return -1;
}
int main(){
    int choice;
    int size;
    choice = menu();
    while(choice<=5){
        int size;
        printf("Enter the size of an Array : ");
        scanf("%d", &size);
        int arr[size];
        
        printf("Enter the Array Elements : \n");
        for(int i = 0; i<size; i++){
            printf("Enter the %d element of Array :", i+1);
            scanf("%d", &arr[i]);
        }
        if (choice ==1){
            bubble_sort(size,arr);
            printf("\n");
        }
        else if(choice == 2){
            insertion_sort(size,arr);
            printf("\n");
        }
        else if(choice == 3){
            Merge_sort(arr, 0, size-1, size);
            printf("\nArray Sorted using Merge Sort \n");
            for (int i = 0; i < size; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        else if(choice == 4){
            int x;
            printf("Enter target Number: ");
            scanf("%d",&x);
            Bubble_sort(size,arr);
            int result = binarySearch(arr, 0, size - 1, x);
            if (result == -1){
                printf("Element is not present in array.\n");
            }
            else{
                printf("Element is present at index %d.\n", result);
            }
        }
        printf("\n\n");
        choice = menu();
    }
    printf("Thank You Visit Again!!");
    return 0;
}