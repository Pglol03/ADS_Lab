#include<stdio.h>
#include<stdlib.h>

#define size 10
int Stack[size];
int top = -1;

void push(){
    int data;
    printf("Enter data :\n");
    scanf("%d", &data);
    if(top==(size-1)){
        printf("Stack is full\n");
        return;
    }
    top++;
    Stack[top] = data;
}

void pop(){
    int data;
    if(top==-1) {
        printf("Stack is empty\n");
        return;
    }
    data = Stack[top];
    top--;
    printf("Popped value is %d", data);
    
}

void peek(){
    int data;
    if(top==-1) {
        printf("Stack is empty\n");
        return;
    }
    data = Stack[top];
    printf("Stack top val is %d", data);

}

void display(){
    int temp = top;
    if(top==-1) {
        printf("Stack is empty\n");
        return;
    }
    while(temp!=-1){
        printf("%d ",Stack[temp]);
        temp--;
    }

}

int main(){
    int choice, loop;
    while(loop){
        printf("\nMenu\n 1 - push \n 2 - pop \n 3 - peek \n 4 - display \n 0 - EXIT \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nPUSH \n");
            push();
            break;
        case 2:
            printf("\nPOP\n");
            pop();
            
            break;
        case 3:
            printf("\nPEEK\n");
            peek();
            
            break;
        case 4:
            printf("\nDISPLAY\n");
            display();
            break;
        
        default:
            printf("\nend\n");
            loop--;
            break;
        }
    }
    return 0;
}