#include <stdio.h>

int main() {
    int *arr = (int*)calloc(5, sizeof(int));
    printf("Enter elements: \n");
    for(in ti=0; i<5; i++){
        scanf("%d", arr+i)
        }
    realloc(arr, 8);
    printf("Enter next value: ");
    scanf("%d", arr+5);
    printf("Enter next value: ");
    scanf("%d", arr+6);
    printf("Array elements are: \n");
    for(int i=0; i<7; i++){
        printf("%d\t", *(arr+i));
    }
    free(arr);
return 0;
}