#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern int n;
extern double *out;
extern int i;
extern int j;
extern double *y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing matrix elements in column-major-like fashion (j * n + i),
    // we reorganize the access to use row strides for better spatial locality in some architectures.
    // We also reverse the outer loop to process from top to bottom but adjust dependencies accordingly.

    double *mat_base = matrix;
    double *out_ptr = out;
    double *y_ptr = y;

    for (i = 0; i < n; i++) {
        int idx = n - 1 - i;  // Reverse index to simulate descending order
        int diag_offset = idx * (n + 1);  // Diagonal element at matrix[idx][idx] using stride (n+1)
        out_ptr[idx] = y_ptr[idx] / mat_base[diag_offset];

        // Inner loop accesses matrix elements with fixed row stride (n), now traversing forward in j
        for (j = idx + 1; j < n; j++) {
            int mat_offset = j * n + idx;  // Original: column-varying, row-fixed per j
            out_ptr[idx] -= mat_base[mat_offset] * out_ptr[j];
        }
    }
}
