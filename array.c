#include <stdio.h>

void readArray(int size, int marks[size]){
    printf("Enter the array elememts: \n");
    for(int i=0; i<size; i++){
        scanf("%d", &marks[i]);
    }
}

void displayArray(int size, int marks[size]){
    printf("Array elements are: \n");
    for(int i=0; i<size; i++){
        printf("%d\n", marks[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int marks[size];
    
    readArray(size, marks);
    displayArray(size, marks);
return 0;
}