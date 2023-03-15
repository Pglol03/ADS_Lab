#include<stdio.h>

void MergeSortDiv(int arr[], int first, int last);
void MergeSortComb(int arr[], int first, int mid, int last);

int main(){
    int s;
    printf("Enter the size of the array\n");
    scanf("%d", &s);

    int a[s];

    for(int i = 0 ; i<s ; i++){
        printf("Enter Array element :\n");
        scanf("%d", &a[i]);
    }

    printf("Non Sorted array is :\n");
    for(int i = 0 ; i<s ; i++){
        printf("%d ",a[i]);
    }

    MergeSortDiv(a,0,s-1);

    printf("Sorted array is :\n");
    for(int i = 0 ; i<s ; i++){
        printf("%d ",a[i]);
    }
}

void MergeSortDiv(int arr[], int first, int last){
    int mid;
    if(first<last){
        mid = (first+last)/2;
        MergeSortDiv(arr, first, mid);
        MergeSortDiv(arr, mid+1,last);
        MergeSortComb(arr, first, mid, last);
    }
}

void MergeSortComb(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    // Create temp arrays
    int L[n1], R[n2];
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back 
    // into arr[l..r]
    // Initial index of first subarray
    i = 0; 
  
    // Initial index of second subarray
    j = 0; 
  
    // Initial index of merged subarray
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements 
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

