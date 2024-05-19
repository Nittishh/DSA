#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prv;
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode() {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->prv = NULL;
    temp->next = NULL;
    return temp;
}

void createDoublyLinkedList() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        struct Node *newNode = createNode();
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prv = tail;
            tail = newNode;
        }
    }
}

void displayDoublyLinkedList() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void displayReverseList() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *temp = tail;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prv;
        }
        printf("\n");
    }
}

void insertNodeInBeg() {
    struct Node *newNode = createNode();
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prv = newNode;
        head = newNode;
    }
}

void insertNodeAtEnd() {
    struct Node *newNode = createNode();
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prv = tail;
        tail = newNode;
    }
}

void insertNodeAtAnyPos() {
    if (head == NULL) {
        printf("List empty\n");
    } else {
        int pos;
        printf("Enter position: ");
        scanf("%d", &pos);
        if (pos == 1) {
            insertNodeInBeg();
        } else {
            int cnt = 1;
            struct Node *temp = head;
            while (temp != NULL && cnt < pos - 1) {
                temp = temp->next;
                cnt++;
            }
            if (temp == NULL) {
                printf("Position out of range\n");
            } else {
                struct Node *newNode = createNode();
                newNode->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prv = newNode;
                } else {
                    tail = newNode;
                }
                newNode->prv = temp;
                temp->next = newNode;
            }
        }
    }
}

void deleteNodeFromGivenPosition() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        int pos;
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        if (pos < 1) {
            printf("Invalid position\n");
        } else if (pos == 1) {
            struct Node *temp = head;
            head = head->next;
            if (head != NULL) {
                head->prv = NULL;
            } else {
                tail = NULL;
            }
            free(temp);
        } else {
            int cnt = 1;
            struct Node *temp = head;
            while (temp != NULL && cnt < pos) {
                temp = temp->next;
                cnt++;
            }
            if (temp == NULL) {
                printf("Position out of range\n");
            } else {
                temp->prv->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prv = temp->prv;
                } else {
                    tail = temp->prv;
                }
                free(temp);
            }
        }
    }
}

void searchNodeInList() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        int key;
        printf("Enter element to search: ");
        scanf("%d", &key);
        struct Node *temp = head;
        int found = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (found) {
            printf("Element %d found in the list\n", key);
        } else {
            printf("Element %d not found in the list\n", key);
        }
    }
}

int main() {
    createDoublyLinkedList();
    while (1) {
        system("cls");
        printf("1. Insert Node In Beginning\n");
        printf("2. Insert Node In End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Given Position\n");
        printf("5. Search Node In List\n");
        printf("6. Display List(forward)\n");
        printf("7. Display List(reverse)\n");
        printf("8. Exit\n");
        int choice;
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertNodeInBeg();
                break;
            case 2:
                insertNodeAtEnd();
                break;
            case 3:
                insertNodeAtAnyPos();
                break;
            case 4:
                deleteNodeFromGivenPosition();
                break;
            case 5:
                searchNodeInList();
                break;
            case 6:
                displayDoublyLinkedList();
                break;
            case 7:
                displayReverseList();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        getchar(); // Consume newline character
        getchar(); // Wait for user to press Enter
    }
    return 0;
}
