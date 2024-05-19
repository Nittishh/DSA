#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createDoublyCircularLinkedList() {
    int n, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }
}

void displayDoublyCircularLinkedList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Doubly Linked Circular List: ");
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
        tail = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }
}

void insertNodeAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
}

void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *curr = head, *prev = NULL;
    while (curr->next != head) {
        if (curr->data == key) {
            if (prev == NULL) {
                head = head->next;
                head->prev = tail;
                tail->next = head;
                free(curr);
                return;
            } else {
                prev->next = curr->next;
                curr->next->prev = prev;
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
            tail = NULL;
        } else {
            prev->next = head;
            head->prev = prev;
            free(curr);
        }
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
    int pos = 1, found = 0;
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
    createDoublyCircularLinkedList();
    displayDoublyCircularLinkedList();
    
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
                displayDoublyCircularLinkedList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
