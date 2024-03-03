#include <stdio.h>

void inputElements(int row, int column, int marks[row][column]){
    
    printf("Enter the elements: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            scanf("%d", &marks[i][j]);
        }
    }
}

void transpose(int row, int column, int transpose_mat[column][row], int marks[row][column]){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            transpose_mat[j][i] = marks[i][j];
        }
    }
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
    int transpose_mat[column][row];

    inputElements(row, column, marks);
    transpose(row, column, transpose_mat, marks);
    displayElements(row, column, transpose_mat);
return 0;
}