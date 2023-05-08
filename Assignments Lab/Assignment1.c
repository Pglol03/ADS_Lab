#include<stdio.h>

void MergeSort(int arr[], int right, int left){
    if(left>right){
        return;
    }
    int mid = (left+right)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, right);
}

void Merge(int arr[], int left, int mid, int right){
    int a1, a2, i, j, k;
    a1 = mid-left+1;
    a2 = right-mid;
    
    int L[a1], R[a2];

    for(i=0 ; i<a1 ; i++){
        L[i] = arr[left+i];
    }
    for(j=0 ; i<a2 ; j++){
        R[i] = arr[mid+1+i];
    }
    
    i = 0;
    j = 0;
    k = left;

    while(i<a1 && j<a2){
        if(L[i]<= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<a1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<a2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void PrintArr(int farr[], int l){
    for(int i = 0; i<size ; i++){
        printf("%d",farr[i]);
    }
    printf("\n");
}

int main(){
    printf("Enter the Array size\n");
    int size = 0;
    scanf("%d",&size);
    int A[size];
    printf("\nEnter the array elements :\n");
    for(int i = 0; i)
    return 0;
}

