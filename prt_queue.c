#include <stdio.h>
#include <stdlib.h> // Required for exit() function
#define MAXSIZE 10
int queue[MAXSIZE], pvt[MAXSIZE];
int front = -1, rear = -1;

int isFull(){
    return rear == MAXSIZE-1;
}

int isEmpty(){
    return front == -1;
}

void enqueue(int value, int p){
    if(isFull()){
        printf("Queue overflow !!!\n");
    }
    else{
        queue[++rear] = value;
        pvt[rear] = p;
        if(front==-1){
            front = rear;
            printf("Element added !!\n");
        }
    }
}

void dequeue(){
    int i, maxp=front;
    if(isEmpty()){
        printf("Queue underflow !!\n");
    }
    else if(front == rear){
        front = rear=-1;
    }
    else{
        for(i=front+1; i<=rear; i++){
            if(pvt[maxp]<pvt[i]){
                maxp=i;
            }
        }
        for(i=maxp; i<rear; i++){
            queue[i]=queue[i+1];
            pvt[i]=pvt[i+1];
        }
        rear--;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty !!!\n");
    }
    else{
        int i;
        printf("Queue elements:\n");
        for(i=front; i<=rear; i++){
                printf("(%d %d)\n", queue[i], pvt[i]);
        }
    }
}

int main(){
    int val, p;
    while(1){
        system("cls"); // Assuming you're running this on a Windows system. If not, use appropriate system clear command
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter value and priority to enqueue: ");
                scanf("%d %d", &val, &p);
                enqueue(val, p);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
