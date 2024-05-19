#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    int priority;
    struct QueueNode *next;
};

struct PriorityQueue {
    struct QueueNode *front;
};

struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* priorityQueue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    if (priorityQueue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    priorityQueue->front = NULL;
    return priorityQueue;
}

void enqueue(struct PriorityQueue* priorityQueue, int data, int priority) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (priorityQueue->front == NULL || priorityQueue->front->priority > priority) {
        newNode->next = priorityQueue->front;
        priorityQueue->front = newNode;
    } else {
        struct QueueNode* temp = priorityQueue->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(struct PriorityQueue* priorityQueue) {
    if (priorityQueue->front == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    struct QueueNode* temp = priorityQueue->front;
    int data = temp->data;
    priorityQueue->front = priorityQueue->front->next;
    free(temp);
    return data;
}

int peek(struct PriorityQueue* priorityQueue) {
    if (priorityQueue->front == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    return priorityQueue->front->data;
}

int isEmpty(struct PriorityQueue* priorityQueue) {
    return (priorityQueue->front == NULL);
}

void display(struct PriorityQueue* priorityQueue) {
    struct QueueNode* temp = priorityQueue->front;
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue* priorityQueue = createPriorityQueue();

    // Enqueue elements
    enqueue(priorityQueue, 10, 2);
    enqueue(priorityQueue, 20, 1);
    enqueue(priorityQueue, 30, 3);

    // Display the priority queue
    display(priorityQueue);

    // Dequeue an element
    printf("Dequeued element: %d\n", dequeue(priorityQueue));

    // Display the priority queue after dequeue
    display(priorityQueue);

    // Peek front element
    printf("Front element: %d\n", peek(priorityQueue));

return 0;
}