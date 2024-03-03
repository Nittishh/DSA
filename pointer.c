#include <stdio.h>

void sum(int *num1, int *num2, int *result) {
    *result = *num1 + *num2;
}

int main() {
    int num1, num2, result;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    sum(&num1, &num2, &result);
    
    printf("Sum of %d and %d is %d\n", num1, num2, result);
    
    return 0;
}

//wap to read and display the element of an array using pointer

#include <stdio.h>

int main() {
    int arr[5]; 
    int *ptr = arr; // Pointer to the first element of the array

    // Read elements into the array using pointers
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", ptr + i); // Using pointer arithmetic to access array elements
    }

    // Display elements using pointers
    printf("Elements of the array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); // Dereferencing pointer to access array elements
    }
    printf("\n");

    return 0;
}



#include <stdio.h>

void Read(int size, int *arr){
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", arr + i);
    }
}

void Display(int size, int *arr){
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d", *(arr + i));
    }
}

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    Read(size, arr);
    Display(size, arr);

    return 0;
}
