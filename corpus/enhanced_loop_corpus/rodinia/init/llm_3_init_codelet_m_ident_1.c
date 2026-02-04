#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern MAT *A;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access via flattened base array
    // Use the base pointer assuming row-major layout to write 1.0 consecutively on diagonal positions
    // Diagonal elements in a square matrix are at indices: 0, n+1, 2n+2, ..., (n-1)*(n+1)
    // We assume A->base is a flattened version of the matrix data and size <= A->max_size
    int n = A->n;
    double *base_ptr = A->base;
    for (i = 0; i < size; i++) {
        int flat_index = i * n + i; // equivalent to [i][i] in 2D
        if (flat_index < A->max_size) {
            base_ptr[flat_index] = 1.;
        }
    }
}
