#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void append(struct Node **refHead, int Data)
{
    struct Node *temp, *newnode;
    temp = *refHead;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = Data;
    newnode->next = NULL;

    if (*refHead == NULL)
    {
        *refHead = newnode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void push(struct Node **refHead, int Data)
{
    struct Node *temp, *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = Data;
    newnode->next = NULL;
    if (*refHead == NULL)
    {
        *refHead = newnode;
        return;
    }
    temp = *refHead;
    newnode->next = temp->next;
    *refHead = newnode;
}

int pop(struct Node **refHead)
{
    int val;
    if (*refHead == NULL)
    {
        printf("List empty\n");
        return 0;
    }
    struct Node *temp;
    temp = *refHead;
    val = temp->data;
    (*refHead) = temp->next;
    return val;
}

void list(struct Node**refHead){
    struct Node* temp;
    temp = (*refHead);
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d \n",temp->data);
}

int main()
{
    struct Node *head = NULL;
    int choice, data, loop;
    loop = 1;
    while (loop)
    {
        printf("\nMenu \n ----------\n 1 - enter data \n 2 - push \n 3 - pop \n 4 - list \n 0 - EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : \n");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 2:
            printf("Enter data to Push : \n");
            scanf("%d", &data);
            push(&head, data);
            break;
        case 3:
            printf("Poped value is : ");
            int val  = 0;
            val = pop(&head);
            printf("%d",val);
            break;
        case 4:
            printf("items in the list is : ");
            list(&head);
            break;
            

        default:
            loop = 0;
            break;
        }
    }
    return 0;
}