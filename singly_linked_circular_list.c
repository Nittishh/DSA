#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createSinglyCircularLinkedList() {
    int n, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            struct Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

void displaySinglyCircularLinkedList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Singly Linked Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void insertNodeAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertNodeAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *prev = NULL, *curr = head;
    while (curr->next != head) {
        if (curr->data == key) {
            if (prev == NULL) {
                struct Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                free(curr);
                return;
            } else {
                prev->next = curr->next;
                free(curr);
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->data == key) {
        if (prev == NULL) {
            head = NULL;
        } else {
            prev->next = head;
        }
        free(curr);
        return;
    }
    printf("Element %d not found in the list.\n", key);
}

int searchNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return 0;
    }
    struct Node *temp = head;
    int found = 0, pos = 1;
    do {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    if (found) {
        printf("Element %d found at position %d.\n", key, pos);
    } else {
        printf("Element %d not found in the list.\n", key);
    }
    return found;
}

int main() {
    createSinglyCircularLinkedList();
    displaySinglyCircularLinkedList();
    
    int choice, data, key;
    while (1) {
        printf("\n1. Insert Node At Beginning\n");
        printf("2. Insert Node At End\n");
        printf("3. Delete Node\n");
        printf("4. Search Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                insertNodeAtBeginning(data);
                break;
            case 2:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                searchNode(key);
                break;
            case 5:
                displaySinglyCircularLinkedList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
