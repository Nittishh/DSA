#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int stack1[SIZE], top1=-1;
int stack2[SIZE], top2=-1;

int isEmpty(int top){
    return (top==-1)?1:0;
}

int isFull(int top){
    return (top==SIZE-1);
}

void push(int stack[], int top){
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

void pop(int stack[], int top){
    if(top == -1){
        printf("Underflow");
    }
    else{
        int val = stack[top];
        top--;
        printf("Value %d is removed from stack...", val);
    }
}

int peek(int stack[], int top){
    if(top != -1){
        return top;
    }
    else{
        return stack[top];
    }
}

void show(int stack[], int top){
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
        printf("1. Push Stack 1\n");
        printf("2. Pop Stack 1\n");
        printf("3. Peek Stack 1\n");
        printf("4. Show Stack 1\n");
        printf("5. Push Stack 2\n");
        printf("6. Pop Stack 2\n");
        printf("7. Peek Stack 2\n");
        printf("8. Show Stack 2\n");
        printf("9. Exit\n");

        int choice,res;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
            push(stack1, top1);
            break;
            case 2:
            pop(stack1, top1);
            break;
            case 3:
            res = peek(stack1, top1);
            if(res == -1)
            printf("Stack empty..");
            else
            printf("%d is available on top of stack");
            break;
            case 4:
            show(stack1, top1);
            break;
            case 5:
            push(stack2, top2);
            break; 
            case 6:
            pop(stack2, top2);
            break;
            case 7:
            res = peek(stack2, top2);
            if(res == -1)
            printf("Stack empty..");
            else
            printf("%d is available on top of stack");
            break;
            case 8:

            show(stack2, top2);
            break;
            case 9:
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