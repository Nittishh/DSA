#include <stdio.h>
#include <stdlib.h>
int main() {
    int *pi = (int *)malloc(sizeof(int));
    int *p2 = (int *)malloc(sizeof(int));
    printf("Enter the nums: ");
    scanf("%d%d", p1,p2);
    printf("Sum = %d", *p1 + *p2);
return 0;
}