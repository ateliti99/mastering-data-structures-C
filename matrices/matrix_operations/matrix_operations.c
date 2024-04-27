#include <stdio.h>
#include <stdlib.h>

/* ################ Declare of structs ################*/
typedef struct
{
    int rows;
    int cols;
    int **A;

} matrix_t;

/* ################ Declaration of functions prototypes ################*/
matrix_t get_matrix();
void print_matrix();

/* Start of the main function */
int main(int argc, char *argv[]){
    matrix_t m1;

    // Get matrices
    m1 = get_matrix(2, 2);

    // Fill matrix values
    for(int i = 0; i < m1.rows; i++){
        for(int j = 0; j < m1.cols; j++){
            m1.A[i][j] = i;
        }
    }

    print_matrix(&m1);

    return 0;
}

/* ################ Definition of the functions ################*/
matrix_t get_matrix(int rows, int cols){
    matrix_t matrix = {.rows = rows, .cols = cols};

    // Allocate memory for the matrix
    matrix.A = malloc(matrix.rows * sizeof(int*)); // Allocate rows
    for (int i = 0; i < matrix.rows; i++) {
        matrix.A[i] = malloc(matrix.cols * sizeof(int)); // Allocate columns
    }

    return matrix;
}

void print_matrix(matrix_t *matrix){
    for(int i = 0; i < matrix->rows; i++){
        for(int j = 0; j < matrix->cols; j++){
            printf("%d ", matrix->A[i][j]);
        }
        printf("\n");
    }
}