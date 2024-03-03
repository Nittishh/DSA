#include <stdio.h>

int main() {
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    int largest = arr[0];
    int secondlargest = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > largest){
            secondlargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondlargest && arr[i] != largest) {
            secondlargest = arr[i];
        }
    }
    printf("Second largest element: %d", secondlargest);
return 0;
}