#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int marks[size];
    int a_marks[size];
    for(int i=0; i<size; i++){
        scanf("%d", &marks[i]);
    }
    printf("Array elements are: \n");
    for(int i=0; i<size; i++){
        a_marks[i] = marks[i];
        printf("%d\n", a_marks[i]);
    }
return 0;
}