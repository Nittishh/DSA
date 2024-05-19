#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};

struct Node *createNode(){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter tree element: ");
    scanf("%d", &temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insertInLeft(struct Node *parent){
    parent->left = createNode();
}

void insertInRight(struct Node *parent){
    parent->right = createNode();
}

struct Node* preorder(struct Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct Node* inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node* postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key > root->data)
        return search(root->right, key);
    
    return search(root->left, key);
}

void searchAndPrint(struct Node* root, int key) {
    struct Node* result = search(root, key);
    if (result != NULL)
        printf("Element %d found in the tree.\n", key);
    else
        printf("Element %d not found in the tree.\n", key);
}

int main(){
    struct Node *root = createNode();
    insertInRight(root);
    insertInLeft(root->right);
    insertInLeft(root);
    insertInLeft(root->right->left);
    insertInLeft(root->right->left->left);

    printf("Enter the value to search: ");
    int key;
    scanf("%d", &key);
    
    searchAndPrint(root, key);
    
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    return 0;
}