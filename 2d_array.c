#include <stdio.h>

void inputElements(int row, int column, int marks[row][column]){
    
    printf("Enter the elements: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            scanf("%d", &marks[i][j]);
        }
    }
}

int matSum(int row, int column, int marks[row][column]){
    printf("Sum is: ");
    int sum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            sum += marks[i][j];
        }
    }
    return sum;
}

void displayElements(int row, int column, int marks[row][column]){
    
    printf("Elements are: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row, column;
    printf("Enter the size of row and column: ");
    scanf("%d %d", &row, &column);
    int marks[row][column];

    inputElements(row, column, marks);
    displayElements(row, column, marks);
    printf("%d\n", matSum(row, column, marks)); 
return 0;
}