#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter the numbers: ");
    scanf("%d%d", &a,&b);
    c = a;
    a = b;
    b = c;
    printf("Swapped values: %d %d", a,b);
return 0;
}

#include <stdio.h>

int main() {
    int a,b;
    printf("Enter the numbers: ");
    scanf("%d%d", &a,&b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("Swapped values: %d %d", a,b);
return 0;
}

#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter the numbers: ");
    scanf("%d%d", &a,&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Swapped values: %d %d", a,b);
return 0;
}