#include<stdio.h>
#define MAX_STACK_SIZE 100
int top = -1;
int stack[MAX_STACK_SIZE];

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top==MAX_STACK_SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int num){
    if(isFull()){
        printf("Stack is Full\n");
    }
    else{
        top++;
        stack[top] = num;
    }
}

int pop(){
    int num;
    if(isEmpty()){
        printf("Stack is Empty\n");
    }
    else{
        num = stack[top];
        top--;
        return num;
    }
    return 0;
}

int main(){
    int state = 1;
    while(state){

    printf("Basic Array Stack\n");
    printf("Enter 1 to add elements to stack\n");
    printf("Enter 2 to delete element from stack\n");
    int s;
    scanf("%d",&s);
    if(s==1){
        printf("Enter element u wanna add to stack :\n");
        int inpt;
        scanf("%d",&inpt);
        push(inpt);
        printf("*************************\n\n");
    }
    else if(s==2){
        printf("Element deleted from stack : ");
        int del;
        del = pop();
        printf("%d\n",del);
        printf("*************************\n\n");
    }
    else{
        state = 0;
    }

    }
}