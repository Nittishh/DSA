#include <stdio.h>
#include <stdlib.h>

char s[100]; // To store the postfix expression
char operator[100];
int top = -1;

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char* convertInfixToPostfix(char *str) {
    int i = 0, x = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            s[x++] = str[i];
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (top == -1 || operator[top] == '(') {
                operator[++top] = str[i];
            }
            else {
                while (top >= 0 && precedence(str[i]) <= precedence(operator[top])) {
                    s[x++] = operator[top--];
                }
                operator[++top] = str[i];
            }
        }
        else if (str[i] == '(') {
            operator[++top] = str[i];
        }
        else if (str[i] == ')') {
            while (operator[top] != '(') {
                s[x++] = operator[top--];
            }
            top--;
        }
        i++;
    }
    
    while (top >= 0) {
        s[x++] = operator[top--];
    }
    s[x] = '\0'; 
    return s; 
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    char *postfix = convertInfixToPostfix(infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}




// infix to prefix




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100]; 
char operator[100];
int top = -1;

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char* convertInfixToPrefix(char *str) {
    int length = strlen(str);
    int i = length - 1, x = 0; 
    while (i >= 0) {
        if (str[i] >= '0' && str[i] <= '9') {
            s[x++] = str[i];
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            if (top == -1 || operator[top] == ')') {
                operator[++top] = str[i];
            }
            else {
                while (top >= 0 && precedence(str[i]) < precedence(operator[top])) {
                    s[x++] = operator[top--];
                }
                operator[++top] = str[i];
            }
        }
        else if (str[i] == ')') {
            operator[++top] = str[i];
        }
        else if (str[i] == '(') {
            while (operator[top] != ')') {
                s[x++] = operator[top--];
            }
            top--; 
        }
        i--;
    }
    
    while (top >= 0) {
        s[x++] = operator[top--];
    }
    s[x] = '\0'; 

    int start = 0, end = x - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    return s; 
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    char *prefix = convertInfixToPrefix(infix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
