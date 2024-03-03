#include <stdio.h>

void Read(int size, int *arr){
    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", arr + i);
    }
}

void Display(int size, int *arr){
    printf("5 elements are:\n");
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