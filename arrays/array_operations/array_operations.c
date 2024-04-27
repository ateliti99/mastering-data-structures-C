#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *A;
    int size;
    int lenght;
} array_t;

void print_array();
void insert_element();
int linear_search();
int binary_search();
array_t add_array();
array_t sum_arrays();

int main(int argc, char *argv[]){
    array_t arr1, arr2, arr3, arr4;
    int element_index;

    // Generate arrays
    arr1 = add_array();
    arr2 = add_array();

    // Display the array
    printf("You input the following arrays:\n");
    print_array(arr1);
    print_array(arr2);

    // Sum the arrays
    arr3 = sum_arrays(&arr1, &arr2);
    printf("The sum of the arrays is:\n");
    print_array(arr3);

    // Insert element in the array
    insert_element(0, &arr3);
    printf("This is the array with the inserted element:\n");
    print_array(arr3);

    // Search for an element
    element_index = linear_search(&arr3, 6);
    printf("The element '2' is in position: %d\n", element_index);

    // Binary search
    element_index = binary_search(&arr3, 6);
    printf("The element '2' is in position: %d\n", element_index);

    return 0;
}

int linear_search(array_t *array, int element){
    for(int i = 0; i < array->lenght; i++){
        if(array->A[i] == element){
            return i;
        }
    }
    return -1;
}

int binary_search(array_t *array, int element){
    int first = 0, last = array->lenght;
    int mid;

    while(first != last){
        // Compute the mid point
        mid = (last + first) / 2;

        // Check the mid value
        if(array->A[mid] == element){
            return mid;
        } else if (array->A[mid] < element){
            first = mid;
        } else {
            last = mid;
        }
    }
    return -1;
}

array_t add_array(){
    // Declare an array variable
    array_t arr;

    // Enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);

    // Allocate memory for the array
    arr.A = (int*)malloc(arr.size*sizeof(int));

    // Fill the array
    printf("Enter the elements of the array\n");
    for(int i = 0; i < arr.size; i++){
        printf("- Array[%d]: ", i);
        scanf("%d", &arr.A[i]);
    }

    // Update the lenght of the array
    arr.lenght = arr.size;

    return arr;
}

void print_array(array_t arr){
    printf("[ ");

    for(int i = 0; i < arr.lenght; i++){
        printf("%d ", arr.A[i]);
    }

    printf("]\n");
}

void insert_element(int position, array_t *array){
    int *p;
    int i;

    // Allocate memory for the new array
    p = (int*)malloc((array->size)*sizeof(int));

    // Copy the previous array in the new allocated space
    for(i = 0; i < position; i++){
        p[i] = array->A[i];
    }
    p[position] = 0;
    for(i = position; i < array->size; i++){
        p[i+1] = array->A[i];
    }

    // Free memory and store the new address
    free(array->A);
    array->A = p;
    p = NULL;

    // Update lenght and size
    array->size += 1;
    array->lenght += 1;
}

array_t sum_arrays(array_t *arr1, array_t *arr2){
    array_t sum;

    // Check the size is the same
    if(arr1->size != arr2->size){
        printf("The size of the arrays do not match, [%d] != [%d]", arr1->size, arr2->size);
        return sum;
    }

    // Allocate memory for the new array
    sum.size = arr1->size;
    sum.lenght = arr1->lenght;
    sum.A = (int*)malloc(sum.size*sizeof(int));

    for(int i = 0; i < arr1->size; i++){
        sum.A[i] = arr1->A[i] + arr2->A[i];
    }

    return sum;
}