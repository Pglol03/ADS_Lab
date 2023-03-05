#include<stdio.h>

void opt1(){
    printf("***Bubble Sort***\n");
    int arr[] = {1, 7, 4, 6, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
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
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}
void opt2(){
    printf("***Insertion Sort***\n");
    int arr[] = {1, 7, 4, 6, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int temp;
    for (int i = 1; i < n; i++) 
    {
        temp = arr[i];
        int j = i - 1;
  
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    for(int i = 0; i<n; i++){
        printf("%d ",arr[i]);
    }
}
void opt3(){

}
void opt4(){

}

int main(){
    int option = 0;
    int quit = 1;
    printf("Welcome to the Program!!!\n");
    do{
        printf("\n");
        printf("\t***MENU***\n");
        printf("Enter '1' for 'Bubble Sort'\n");
        printf("Enter '2' for 'Insertion Sort'\n");
        printf("Enter '3' for 'Merge Sort'\n");
        printf("Enter '4' for 'Search Binary Search'\n");
        printf("Enter '5' to Exit\n");
        printf("******************************\n");
        scanf("%d",&option);

        switch (option){
            case 1:
                opt1();
                break;

            case 2:
                opt2();
                break;

            case 3:
                opt3();
                break;

            case 4:
                opt4();
                break;

            case 5:
                quit = 0;
                break;
            
            default:
            printf("Wrong Input, try again!");
                break;
        }
    }while(quit == 1);
    
}