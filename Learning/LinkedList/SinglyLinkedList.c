#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data; //    A Data Item (we can store integers, strings, or any type of data).
    struct Node* next;  //  Pointer (Or Reference) to the next node (connects one node to another)
};

void printlist(struct Node* n){
    while(n != NULL){
        printf(" %d \n", n->data);
        n = n->next;
    }
}

int main(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //  Allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = NULL;

    printlist(head);

    return 0;
}