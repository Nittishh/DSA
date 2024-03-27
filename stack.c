#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int stack[SIZE], top=-1;

int isEmpty(){
    return (top==-1)?1:0;
}

int isFull(){
    return (top==SIZE-1);
}

void push(){
    if(isFull){
        printf("Stack Overfow!!!!");
    }
    else{
        top++;
        int val;
        printf("Enter element: ");
        scanf("%d", &val);
        stack[top]=val; 
        printf("Element inserted .....");
    }
}

void pop(){
    if(top == -1){
        printf("Underflow");
    }
    else{
        int val = stack[top];
        top--;
        printf("Value %d is removed from stack...", val);
    }
}

int peek(){
    if(top != -1){
        return top;
    }
    else{
        return stack[top];
    }
}

void show(){
    if (top == -1){
        printf("Stack is Empty !!!");
    }
    else{
        for(int i=0; i<=top; i++){
            printf("%d\n",stack[i]);
        }
    }
}

int main() {
    while(1){
        system("cls");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Show\n");
        printf("5. Exit\n");
        int choice,res;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            res = peek();
            if(res == -1)
            printf("Stack empty..");
            else
            printf("%d is available on top of stack");
            break;
            case 4:
            show();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("Invalid Choice....");
            break;
        }
        printf("\n\n");
        system("pause");
    }
return 0;
}