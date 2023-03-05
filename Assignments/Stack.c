#define MaxStackSize 100
int top = -1;
int Stack[MaxStackSize];

//  Functions for stack
int isEmpty(){
    if (top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if (top==(MaxStackSize-1)){
        return 1;
    }
    else{
        return 0;
    } 
}
void push(int num){
    if(isFull){
        printf("\nStack is full");
    }
    top += 1;
    Stack[top] = num;
}
int pop(){
    int num;
    if(isEmpty){
        printf("\nStack is empty");
    }
    num = Stack[top];
    top--;
    return num;
}

//  Main Method

int main(){

    return 0;
}