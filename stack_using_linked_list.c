#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode *next;
};

struct StackNode *top = NULL;

struct StackNode *createStackNode(int data) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data) {
    struct StackNode *newNode = createStackNode(data);
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    int data = top->data;
    struct StackNode *temp = top;
    top = top->next;
    free(temp);
    return data;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

int main() {
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            }
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                printf("Top element: %d\n", peek());
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice....\n");
                break;
        }
    }
    return 0;
}
