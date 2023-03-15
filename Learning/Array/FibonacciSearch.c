#include<stdio.h>
#include<math.h>
int FibonacciSearch(int arr[], int x,int n);
int min(int x, int y)
    {
        return (x <= y) ? x : y;
    }

int main(){
    int s;
    printf("Enter the size of the array :\n");
    scanf("%d",&s);

    int a[s];

    for(int i = 0 ; i<s ; i++){
        printf("Enter Array elements : \n");
        scanf("%d",&a[i]);
    }

    int Search;
    printf("Enter Element you want to search : \n");
    scanf("%d",&Search);

    int find = FibonacciSearch(a,Search, s);
    //find++;

    if(find<0){
        printf("Did not find your element\n");
    }
    else{
        printf("Found '%d' at the position : %d\n",Search,find);
    }
}

int FibonacciSearch(int arr[], int x,int n)
    {
        /* Initialize fibonacci numbers */
        int fibMMm2 = 0; // (m-2)'th Fibonacci No.
        int fibMMm1 = 1; // (m-1)'th Fibonacci No.
        int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci
 
        /* fibM is going to store the smallest
        Fibonacci Number greater than or equal to n */
        while (fibM < n) {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM = fibMMm2 + fibMMm1;
        }
 
        // Marks the eliminated range from front
        int offset = -1;
 
        /* while there are elements to be inspected.
        Note that we compare arr[fibMm2] with x.
        When fibM becomes 1, fibMm2 becomes 0 */
        while (fibM > 1) {
            // Check if fibMm2 is a valid location
            int i = min(offset + fibMMm2, n - 1);
 
            /* If x is greater than the value at
            index fibMm2, cut the subarray array
            from offset to i */
            if (arr[i] < x) {
                fibM = fibMMm1;
                fibMMm1 = fibMMm2;
                fibMMm2 = fibM - fibMMm1;
                offset = i;
            }
 
            /* If x is less than the value at index
            fibMm2, cut the subarray after i+1 */
            else if (arr[i] > x) {
                fibM = fibMMm2;
                fibMMm1 = fibMMm1 - fibMMm2;
                fibMMm2 = fibM - fibMMm1;
            }
 
            /* element found. return index */
            else
                return i;
        }
 
        /* comparing the last element with x */
        if (fibMMm1 == 1 && arr[n-1] == x)
            return n-1;
 
        /*element not found. return -1 */
        return -1;
    }