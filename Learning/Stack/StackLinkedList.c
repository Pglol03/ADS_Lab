#include <stdio.h>
#define MAX_STACK_SIZE 100

struct Node{
    int data;
    struct Node *next;
};


void push(struct Node **head, int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *head;
    *head = node; // top
}

void pop(struct Node **head){
    if (isEmpty(*head))
        printf("Stack is Empty");
    struct Node *temp = *head;
    *head = (*head)->next;
    int num = temp->data;
    free(temp);
    printf(" Popped element: %d", num);
}
