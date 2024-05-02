#ifndef D20A11F1_431E_43EC_86E1_47671B3DB1CF
#define D20A11F1_431E_43EC_86E1_47671B3DB1CF

// Represents a sparse matrix using coordinate representation
typedef struct SparseMatrix_t
{
    int* values;
    int* row;
    int* col;
    int num_rows;
    int num_cols;
    int non_zero_elements;
    
} SparseMatrix_t;

// Allocate a sparse 2D matrix using coordinate format
SparseMatrix_t to_sparse_matrix(int** matrix, int num_rows, int num_cols){
    static SparseMatrix_t sparse_matrix;
    int i, j, k;

    // Add matrix dimensions to the struct
    sparse_matrix.num_rows = num_rows;
    sparse_matrix.num_cols = num_cols;

    // Initialize num of non zero elements to zero and count them O(n)
    sparse_matrix.non_zero_elements = 0;
    for(i = 0; i < num_rows; i++){
        for(j = 0; j < num_cols; j++){
            if(matrix[i][j] != 0){
                sparse_matrix.non_zero_elements++;
            }
        }
    }

    printf("Non zero elements founded: %d\n", sparse_matrix.non_zero_elements);

    // Allocate memory for the coordinate representation
    sparse_matrix.values = (int*)malloc(sparse_matrix.non_zero_elements * sizeof(int));
    sparse_matrix.row = (int*)malloc(sparse_matrix.non_zero_elements * sizeof(int));
    sparse_matrix.col = (int*)malloc(sparse_matrix.non_zero_elements * sizeof(int));

    // Add values to the sparse matrix
    k = 0;
    for(i = 0; i < num_rows; i++){
        for(j = 0; j < num_cols; j++){
            // Break if all elements are already added
            if(k == sparse_matrix.non_zero_elements){
                break;
            }
            
            // Add non zero element to the sparse matrix
            if(matrix[i][j] != 0){
                sparse_matrix.values[k] = matrix[i][j];
                sparse_matrix.row[k] = i;
                sparse_matrix.col[k] = j;
                k++;
            }
        }
    }
    
    return sparse_matrix;
}

#endif /* D20A11F1_431E_43EC_86E1_47671B3DB1CF */
