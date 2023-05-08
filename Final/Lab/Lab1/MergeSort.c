#include<stdio.h>

void Merge(int arr[], int l, int m, int r){
    int t1, t2;
    t1 = m-l+1;
    t2 = r-m;
    int temp1[t1],temp2[t2];
   for (int i = 0; i < t1; i++)
		temp1[i] = arr[l + i];
	for (int j = 0; j < t2; j++)
		temp2[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while(i<t1 && j<t2){
        if(temp1[i]<=temp2[j]){
            arr[k] = temp1[i];
            i++;
        }
        else{
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    
     while (i < t1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }
     while (j < t2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void MergeSorting(int a[], int left, int right){
   if(left<right){
    int mid = left + (right-left)/2;
    MergeSorting(a,left,mid);
    MergeSorting(a,mid+1,right);
    Merge(a,left, mid, right);
    }
}
// void MergeSorting(int arr[], int l, int r)
// {
//     if (l < r) {
//         // Same as (l+r)/2, but avoids overflow for
//         // large l and h
//         int m = l + (r - l) / 2;
 
//         // Sort first and second halves
//         MergeSorting(arr, l, m);
//         MergeSorting(arr, m + 1, r);
 
//         Merge(arr, l, m, r);
//     }
// }

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSorting(arr, 0, arr_size - 1);
    printf("Sorted array is : \n");
    for(int i = 0; i<arr_size ; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}