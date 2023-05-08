#include<stdio.h>

void BubbleSort(int arr[], int l);

int main(){
    int s;
    printf("Enter the size of the array :\n");
    scanf("%d", &s);

    int* a[s];
    for (int i = 0; i < s; i++)
    {
        printf("Enter Array Elements : \n");
        scanf("%d", a[i]);
    }
    BubbleSort(a, s);
    //int arr[] = {1, 7, 4, 6, 2};
    
    printf("Sorted Array :\n");
    for(int i = 0; i<s; i++){
        printf("%d ",a[i]);
    }
}

void BubbleSort(int arr[l], int l)
{   
    int n = l;
    for(int i = 0; i<n-1; i++){
        for (int j = 0; j<n-i-1; j++){
            if (arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }  
    }
}
