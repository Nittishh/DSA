#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

int peek(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->data;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void display(struct Queue* queue) {
    struct QueueNode* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Display the queue
    display(queue);

    // Dequeue an element
    printf("Dequeued element: %d\n", dequeue(queue));

    // Display the queue after dequeue
    display(queue);

    // Peek front element
    printf("Front element: %d\n", peek(queue));

return 0;
}