// Circular Queue implementation in C

#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
  }
}

// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() {
  // Fails because front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fails to enqueue because front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  // Fails to enqueue because front == rear + 1
  enQueue(8);

  return 0;
}

// Java code to reverse a stack using queue
#define MAX 100

void show(int stack[],int size,int top)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("\nValue at %d is %d",top,stack[top]);
        top=top-1;
    }
}

void reverse(int stack[],int qu[],int *t,int *r,int *f)
{
    *f=0;
    while(*t>-1)
    {
        *r=*r+1;
        qu[*r]=stack[*t];
        *t=*t-1;
    }
    while(*f<=*r)
    {
        *t=*t+1;
        stack[*t]=qu[*f];
        *f=*f+1;
    }
}

void main()
{
    int size;
    int item,t,i,stack[MAX],quee[MAX];
    int top=-1,front=-1,rear=-1;

    printf("Enter size of stack::");
    scanf("%d",&size);

    for(i=0;i<size;i++)
    {
        top=top+1;
        printf("Enter value of for position %d ::",top);
        scanf("%d",&item);
        stack[top]=item;
    }

    show(stack,size,top);
    reverse(stack,quee,&top,&rear,&front);

    printf("\nAfter reverse..............");
    show(stack,size,top);

    getch();
}
