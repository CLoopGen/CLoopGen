#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double alpha;
extern double beta;
extern double C[1200][1200];
extern double A[1200][1000];
extern double B[1200][1000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *c_ptr, *a_ptr_j, *b_ptr_j, *a_ptr_i, *b_ptr_i;
for (i = 0; i < n; i++) {
    c_ptr = &C[i][0];  // Base pointer to row i of C
    for (j = 0; j <= i; j++) {
        *(c_ptr + j) *= beta;  // Consecutive memory access via pointer arithmetic
    }
    for (k = 0; k < m; k++) {
        a_ptr_i = &A[i][k];  // Reused address for A[i][k]
        b_ptr_i = &B[i][k];  // Reused address for B[i][k]
        for (j = 0; j <= i; j++) {
            a_ptr_j = &A[j][k];  // Row-varying column-fixed access
            b_ptr_j = &B[j][k];
            c_ptr = &C[i][j];
            *c_ptr += (*a_ptr_j) * alpha * (*b_ptr_i) + (*b_ptr_j) * alpha * (*a_ptr_i);
        }
    }
}
}
