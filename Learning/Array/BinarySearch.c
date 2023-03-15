#include <stdio.h>

int BinarySearch(int arr[], int x, int l);

int main()
{
    int s;
    printf("Enter the size of the array :\n");
    scanf("%d", &s);

    int a[s];
    for (int i = 0; i < s; i++)
    {
        printf("Enter Array Elements : \n");
        scanf("%d", &a[i]);
    }

    int Search;
    printf("Enter Element you want to search\n");
    scanf("%d", &Search);

    int find = BinarySearch(a, Search, s);
    //find++;

    if(find<0){
        printf("Did not find your element");
    }
    else{
        printf("Found element '%d' at position : %d\n",Search,find);
    }
    return 0;
}

int BinarySearch(int arr[], int x, int l)
{
    int low = 0;
    int high = l - 1;
    int mid;

    while (high-low>1)
    {
        mid = (low + high) / 2;
        if (arr[mid] < x){
            low = mid + 1;
        }
        else if (arr[mid] > x){
            high = mid - 1;
        }
        else{
            return mid; // target found }
        }
    }
    return -1;
}