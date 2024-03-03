#include <stdio.h>

int main() {
    int size,sum=0;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int marks[size];
    for(int i=0; i<size; i++){
        scanf("%d", &marks[i]);
         sum += marks[i];
    }
    
    printf("Sum: \n");
    printf("%d\n", sum);
return 0;
}