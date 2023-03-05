#define MaxQueueSize 100
int front, rear = -1;
int queue[MaxQueueSize];

// Functions for Circular Queue

int isFull(){
    if((front==0 && rear == (MaxQueueSize-1)) || (front == rear+1)){
        printf("\nQueue is full");
        return 1;
    }
    else{
        return 0;
    }
}
void isEmpty(){
    if(front == -1){
        printf("\nQueue is empty");
        return 1;
    }
    else{
        return 0;
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