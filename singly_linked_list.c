#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode() {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &node->data);
    node->next = NULL;
    return node;
}

void createlist() {
    int n, i;
    struct Node *temp;
    printf("Enter total number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        struct Node *newNode = createNode();
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty !!!\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void insertNodeInBeg() {
    struct Node *newNode = createNode();
    newNode->next = head;
    head = newNode;
}

void insertInEnd() {
    struct Node *newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertNodeAtAnyLoc(){
    if(head==NULL){
        printf("Invalid Position !!!\n");
    }
    else{
        int pos, cnt=1;
        printf("Enter position: ");
        scanf("%d", &pos);
        if(pos==1){
            struct Node* newNode = createNode();
            newNode->next = head;
            head = newNode;
        }
        else{
            struct Node *temp=head;
            while(temp->next!=NULL){
                if(cnt == pos-1){
                    break;
                }
                cnt++;
                temp = temp->next;
            }
            if(temp->next == NULL){
                printf("Invalid Position !!!\n");
            }
            else{
                struct Node *newNode = createNode();
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
    }
}

void deleteFromAnyPos(){
    if(head==NULL){
        printf("Invalid Position !!!\n");
    }
    else{
        int pos, cnt=1;
        printf("Enter position: ");
        scanf("%d", &pos);
        if(pos==1){
            head = head->next;
        }
        else{
            struct Node *temp=head;
            while(temp->next!=NULL){
                if(cnt == pos-1){
                    break;
                }
                cnt++;
                temp = temp->next;
            }
            if(temp->next == NULL){
                printf("Invalid Position !!!\n");
            }
            else{
                temp->next = temp->next->next;
            }
        }
    }
}

void searchNode(){
    if(head==NULL){
        printf("List is empty !!!\n");
    }
    else{
        int num, flag=0;
        printf("Enter data to search: ");
        struct Node *temp = head;
        while(temp!=NULL){
            if(temp->data == num){
                flag=1;
                break;
            }
            temp = temp->next;
        }
        if(flag==1){
            printf("Found!!!\n");
        }
        else{
            printf("Not Found !!!\n");
        }
    }
}

int main() {
    createlist();
    while (1) {
        printf("\n1. Insert Node In Beginning\n");
        printf("2. Insert Node In End\n");
        printf("3. Insert Node At Any Position\n");
        printf("4. Delete Node From Given Position\n");
        printf("5. Search Node In List\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertNodeInBeg();
                break;
            case 2:
                insertInEnd();
                break;
            case 3:
                insertNodeAtAnyLoc();
                break;
            case 4:
                deleteFromAnyPos();
                break;
            case 5:
                break;
            case 6:
                displayList();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid Choice....");
                break;
        }
    }
    return 0;
}
