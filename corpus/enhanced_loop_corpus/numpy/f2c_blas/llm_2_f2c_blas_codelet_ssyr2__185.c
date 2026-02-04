#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *alpha;
extern real *x;
extern real *y;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Array Reindexing
    // Instead of accessing a[i__ + j * a_dim1], we precompute the base pointer for column j
    // and access elements consecutively in the inner loop to improve spatial locality.
    integer base_idx;
    real *a_col_j;

    for (j = 1; j <= i__1; ++j) {
        if (x[j] != 0.F || y[j] != 0.F) {
            temp1 = *alpha * y[j];
            temp2 = *alpha * x[j];
            i__2 = *n;

            // Precompute base address of column j in matrix 'a'
            base_idx = j * a_dim1;
            a_col_j = &a[base_idx];

            for (i__ = j; i__ <= i__2; ++i__) {
                // Access a[i__][j] as a_col_j[i__], enabling more predictable access
                a_col_j[i__] = a_col_j[i__] + x[i__] * temp1 + y[i__] * temp2;
            }
        }
    }
}
