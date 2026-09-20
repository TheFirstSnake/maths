#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int rows;
    int cols;
    int matrix [MAX][MAX];
}Matrices;

Matrices multiplication(Matrices compA, Matrices compB) {
    Matrices result = {0}; result.rows = compA.rows; result.cols = compB.cols;
    for (int i = 0; i<compA.rows; i++) {
        for (int j = 0; j<compB.cols; j++) {
           for (int k = 0; k<compA.cols; k++){
               result.matrix[i][j] = result.matrix[i][j] + ( compA.matrix[i][k] * compB.matrix[k][j] );
            }
        }
    }
    return result;
}

int main() {
    Matrices compA = {0}; Matrices compB = {0};
    printf("Enter the size of the matrices");
    scanf("%d",&compA.rows);
    scanf("%d",&compA.cols);
    for (int i = 0; i<compA.rows; i++){
        for (int j = 0; j<compA.cols; j++){
            scanf("%d",&compA.matrix[i][j]);
        }
    }
    compB = compA;
    Matrices result = multiplication(compA, compB);
    for (int i = 0; i<result.rows; i++){
        for (int j = 0; j<result.cols; j++){
            printf("%d ",result.matrix[i][j]);
        }
    }
    return 0;
}
