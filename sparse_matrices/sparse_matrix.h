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

// Sum two sparse matrix
SparseMatrix_t sum_sparse_matrix(SparseMatrix_t* m1, SparseMatrix_t* m2){
    SparseMatrix_t m_sum;
    int i, j, k;

    // Check that is possible to sum the matrices
    if(m1->num_rows != m2->num_rows || m1->num_cols != m2->num_cols){
        printf("Matrices dimension to not coincide!\n");
        return m_sum;
    }
    
    // Add number of rows and cols to the sum matrix
    m_sum.num_rows = m1->num_rows;
    m_sum.num_cols = m1->num_cols;

    // Allocate space for at least the sum of non-zero elements
    m_sum.non_zero_elements = m1->non_zero_elements + m2->non_zero_elements; // not the correct value
    m_sum.row = (int*)malloc(m_sum.non_zero_elements * sizeof(int));
    m_sum.col = (int*)malloc(m_sum.non_zero_elements * sizeof(int));
    m_sum.values = (int*)malloc(m_sum.non_zero_elements * sizeof(int));

    // Sum the matrices
    i = 0, j = 0, k = 0;
    while(i < m1->non_zero_elements && j < m2->non_zero_elements){
        if(m1->row[i] < m2->row[j]){
            m_sum.row[k] = m1->row[i];
            m_sum.col[k] = m1->col[i];
            m_sum.values[k] = m1->values[i];
            i++;
        }else if(m1->row > m2->row){
            m_sum.row[k] = m2->row[j];
            m_sum.col[k] = m2->col[j];
            m_sum.values[k] = m2->values[j];
            j++;
        }else{
            if(m1->col < m2->col){
                m_sum.row[k] = m1->row[i];
                m_sum.col[k] = m1->col[i];
                m_sum.values[k] = m1->values[i];
                i++;
            }else if(m1->col > m2->col){
                m_sum.row[k] = m2->row[j];
                m_sum.col[k] = m2->col[j];
                m_sum.values[k] = m2->values[j];
                j++;
            }else{
                m_sum.row[k] = m1->row[i];
                m_sum.col[k] = m1->col[i];
                m_sum.values[k] = m1->values[i] + m2->values[j];
                i++;
                j++;
            }
        }
        k++;
    }

    // Copy all the remaning elements
    while(i < m1->non_zero_elements){
        m_sum.row[k] = m1->row[i];
        m_sum.col[k] = m1->col[i];
        m_sum.values[k] = m1->values[i];
        i++;
        k++;
    }

    while(j < m2->non_zero_elements){
        m_sum.row[k] = m2->row[j];
        m_sum.col[k] = m2->col[j];
        m_sum.values[k] = m2->values[j];
        j++;
        k++;
    }
    
    // Update the correct number of non-zero elements
    m_sum.non_zero_elements = k;

    return m_sum;
}

#endif /* D20A11F1_431E_43EC_86E1_47671B3DB1CF */
