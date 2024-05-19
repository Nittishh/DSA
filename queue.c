#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) 
    front = 0;
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    front++;
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue[front];
}

int isEmpty() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return 1;
    }
    return 0;
}

int isFull() {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return 1;
    }
    return 0;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Front element: %d\n", peek());

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    
    enqueue(40);
    
    return 0;
}

