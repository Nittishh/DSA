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
            if(i==j){
                sum += marks[i][j];
                }
        }
    }
    printf("%d ", sum);
return 0;
}