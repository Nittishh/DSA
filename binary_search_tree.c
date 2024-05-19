// #include <stdio.h>
// #include <stdlib.h>
// struct Node{
//     struct Node *left;
//     int data;
//     struct Node *right;
// };
// struct Node *createNode(int val){
//     struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
//     temp->data = val;
//     temp->left=temp->right=NULL;
//     return temp;
// }

// struct Node* insert(struct Node *root, int value){
//     if(root==NULL){
//         root = createNode(value);
//     }
//     else if(value<root->data){
//         root->left=insert(root->left,value);
//     }
//     else{
//         root->right=insert(root->right,value);
//     }
//     return root;
// }
// struct Node* preorder(struct Node *root){
//     if(root != NULL){
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// struct Node* inorder(struct Node *root){
//     if(root != NULL){
//         inorder(root->left);
//         printf("%d ", root->data);
//         inorder(root->right);
//     }
// }

// struct Node* postorder(struct Node *root){
//     if(root != NULL){
//         postorder(root->left);
//         postorder(root->right);
//         printf("%d ", root->data);
//     }
// }

// struct Node* search(struct Node* root, int key) {
//     if (root == NULL || root->data == key)
//         return root;
    
//     if (key > root->data)
//         return search(root->right, key);
    
//     return search(root->left, key);
// }

// void searchAndPrint(struct Node* root, int key) {
//     struct Node* result = search(root, key);
//     if (result != NULL)
//         printf("Element %d found in the tree.\n", key);
//     else
//         printf("Element %d not found in the tree.\n", key);
// }

// void descendingOrder(struct Node* root){
//     if(root != NULL){
//         inorder(root->right);
//         printf("%d ", root->data);
//         inorder(root->left);
//     }
// }

// struct Node *deleteElement(struct Node *root, int key){
//     if(root == NULL){
//         return root;
//     }
//     else if(key < root->data){
//         root->left = deleteElement(root->left,key);
//         return root;
//     }
//     else if(key > root->data){
//         root->right = deleteElement(root->right,key);
//     }
//     else{
//         if(root->left==NULL){
//             return root->right;
//         }
//         else if(root->right==NULL){
//             return root->left;
//         }
//         else{
//             struct Node *temp = root->right;
//             while(temp->left != NULL){
//                 temp=temp->left;
//             }
//             root->data = temp->data;
//             root->right=deleteElement(root->right, temp->data);
//             return root;
//         }
//     }
// }

// int main(){
//     int val, choice;
//     struct Node* root = NULL;
    
//     while(1){
//         system("cls");
//         printf("********Binary Search Tree**********\n");
//         printf("1. Insert Node\n");
//         printf("2. Pre-order\n");
//         printf("3. Inorder\n");
//         printf("4. Post-order\n");
//         printf("5. Search any Node\n");
//         printf("6. Descending order\n");
//         printf("7. Delete element\n");
//         printf("8. Exit\n");
//         printf("Enter choice: ");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//         printf("Enter the Node: ");
//         scanf("%d", &val);
//         root = insert(root, val);
//             break;
//         case 2:
//         preorder(root);
//             break;
//         case 3:
//         inorder(root);
//             break;
//         case 4:
//         postorder(root);
//             break;
//         case 5:
//         printf("Enter the value to search: ");
//         int key;
//         scanf("%d", &key);
    
//         searchAndPrint(root, key);
//             break;
//         case 6:
//         descendingOrder(root);
//             break;
//         case 7:
//         printf("Enter key: ");
//         scanf("%d", &key);
//         root = deleteElement(root,key);
//             break;
//         case 8:
//         exit(0);
//             break;
        
//         default:
//         printf("Invalid choice");
//             break;
//         }
//         printf("\n\n");
//         system("pause");
//     }
//     return 0; 
// }





#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the binary search tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform inorder traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the binary search tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the binary search tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in the binary search tree
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    }

    return search(root->right, value);
}

// Driver program
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    int key = 60;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("%d found in the tree.\n", key);
    } else {
        printf("%d not found in the tree.\n", key);
    }

    return 0;
}