#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"

SparseMatrix_t to_sparse_matrix(int** matrix, int num_rows, int num_cols);

int main(){
    int num_rows = 2;
    int num_cols = 2;
    int** matrix;
    SparseMatrix_t sparse_matrix;

    // Allocate space for the matrix
    matrix = (int**)malloc(num_rows * sizeof(int*));
    for(int i = 0; i < num_cols; i++){
        matrix[i] = (int*)malloc(num_cols * sizeof(int));
    }

    // Add dummy value to the matrix
    matrix[0][0] = 0; 
    matrix[0][1] = 1;
    matrix[1][0] = 0;
    matrix[1][1] = 5;

    // Print matrix values
    printf("Dense Matrix: [ ");
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            printf("%d ", matrix[i][j]);
        }
    }
    printf("]\n");

    // Convert the matrix in a sparse matrix
    sparse_matrix = to_sparse_matrix(matrix, num_rows, num_cols);

    // Print the coordinate format
    printf("v|r|c\n");
    for(int i = 0; i < sparse_matrix.non_zero_elements; i++){
        printf("%d|%d|%d\n", sparse_matrix.values[i], sparse_matrix.row[i], sparse_matrix.col[i]);
    }

    return 0;
}