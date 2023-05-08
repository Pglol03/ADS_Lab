#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    return newnode;
}

void append(struct node** refHead, int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* last = *refHead;
    newnode->data = data;
    newnode->next = NULL;
    if(*refHead==NULL){
        *refHead = newnode;
        return;
    }

    while(last->next!=NULL) { last = last->next; }
    last->next = newnode;
    return;
}
int sizeLL(struct node** head){
    struct node  *temp;
    temp = *head;
    int len;
    while(temp->next!=0){ 
        temp = temp->next;
        len++;
    }
    return len;
}

void traverseLL(struct node** head){
    struct node  *temp;
    temp = *head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

}

int main(){
    struct node* head, *newnode, *temp;
    head = NULL;
    int choice, data, size;
    printf("Enter 1 to enter data and 0 to end\n");
    scanf("%d",&choice);
    while(choice){
        printf("Enter value\n");
        scanf("%d",&data);
        // newnode = createNode(data);
        // if(head==0) { head = temp = newnode; }
        // else{
        //     temp->next = newnode;
        //     temp = newnode;
        // }
        append(&head,data);
        printf("Do you want to continue? 1-yes 0-no\n");
        scanf("%d",&choice);
    }
    printf("\n\n");
    size  = sizeLL(&head);
    printf("Size of the linked list is : %d\n", size);

    printf("Traverse Linked List : ");
    traverseLL(&head);


    return 0;
}