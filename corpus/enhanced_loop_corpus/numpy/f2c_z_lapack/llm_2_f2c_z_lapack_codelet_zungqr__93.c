#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Consecutive access via pointer arithmetic
    // Instead of accessing a[i__ + j * a_dim1] which may be strided, we precompute the base address per column
    // and traverse consecutively in inner loop assuming row-major layout or transformed indexing.
    // We reinterpret the matrix as being accessed column-wise with consecutive memory writes.

    integer base_idx;
    doublecomplex *col_start;

    for (j = kk + 1; j <= i__1; ++j) {
        base_idx = j * a_dim1 + 1;  // Starting index for column j (1-based offset)
        col_start = &a[base_idx];   // Pointer to first element in column j

        for (i__ = 0; i__ < kk; ++i__) {  // Now i__ goes from 0 to kk-1 for consecutive access
            col_start[i__].r = 0.0;
            col_start[i__].i = 0.0;
        }
    }
}
