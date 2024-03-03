#include <stdio.h>

int main() {
    int row, column, sum=0;
    printf("Enter the size of row and column: ");
    scanf("%d %d", &row, &column);
    int marks[row][column];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            scanf("%d", &marks[i][j]);
        }
    }
    printf("Sum: \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            sum += marks[i][j];
        }
    }
    printf("%d ", sum);
return 0;
}


#include <stdio.h>

int main() {
    int row, column;
    printf("Enter the size of row and column: ");
    scanf("%d %d", &row, &column);
    int marks[row][column];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            scanf("%d", &marks[i][j]);
        }
    }
    printf("Rowsum: \n");
    for(int i=0; i<row; i++){
        int rowsum=0;
        for(int j=0; j<column; j++){
            rowsum += marks[i][j];
        }
        printf("%d ", rowsum);
    }
    printf("\nColsum: \n");
    for(int j=0; j<column; j++){
        int colsum=0;
        for(int i=0; i<row; i++){
            colsum += marks[i][j];
        }
        printf("%d ", colsum);
    }
return 0;
}



#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the size of row and column of both matrices: ");
    scanf("%d %d", &rows, &cols);
    int mat1[rows][cols];
    int mat2[rows][cols];
    int result[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("Sum: \n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
return 0;
}
