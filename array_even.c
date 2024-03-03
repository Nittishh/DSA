#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int marks[size];
    for(int i=0; i<size; i++){
        scanf("%d", &marks[i]);
    }
    printf("Array elements are: \n");
    for(int i=0; i<size; i++){
        if(marks[i]%2==0){
        printf("%d\n", marks[i]);
        }
    }
return 0;
}