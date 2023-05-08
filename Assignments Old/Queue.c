#define MaxQueueSize 100
int front, rear = -1;
int queue[MaxQueueSize];

// Functions for Queue

void isEmpty(){
    if(front == rear){
        printf("\nQueue is empty");
    }
}
void isFull(){
    if(rear == (MaxQueueSize-1)){
        printf("\nQueue is Full");
    }
}
void EnQueue(int num){
    if (rear==(MaxQueueSize-1)){
        printf("\nQueue is full");
    }
    else{
        rear += 1;
        queue[rear] = num;
    }
    
}
void DeQueue(){
    if (front==rear){
        printf("\nQueue is Empty");
    }
    else{
        front++;
        printf("\nDeleted Element is %d",queue[front]);
    }
}
void QueueDisplay(){
    printf("\nQueue elements are : \n");
    if(front==rear){
        printf("\nQueue is empty");
    }
    else{
        for(int i = (front+1) ; i <= rear ; i++){
            printf("\t%d",queue[i]);
        }
    }
}