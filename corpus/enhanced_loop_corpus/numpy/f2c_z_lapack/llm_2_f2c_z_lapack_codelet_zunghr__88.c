#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *n;
extern integer *ihi;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Modify memory access pattern to use consecutive indexing with pointer arithmetic
// Instead of recalculating index i__ + j*a_dim1 repeatedly, we compute base pointers per column j
integer j_start = *ihi;
integer j_end = i__1;
for (j = j_start; j >= j_end; --j) {
    doublecomplex *a_col_j = &a[j * a_dim1];  // Base pointer for column j
    doublecomplex *a_col_prev = &a[(j - 1) * a_dim1];  // Base pointer for column j-1

    // Zero out elements above diagonal in column j: rows [1, j-1]
    for (i__ = 1; i__ <= j - 1; ++i__) {
        a_col_j[i__].r = 0.0;
        a_col_j[i__].i = 0.0;
    }

    // Copy from previous column: rows [j+1, ihi]
    for (i__ = j + 1; i__ <= *ihi; ++i__) {
        a_col_j[i__].r = a_col_prev[i__].r;
        a_col_j[i__].i = a_col_prev[i__].i;
    }

    // Zero out elements below ihi in column j: rows [ihi+1, n]
    for (i__ = *ihi + 1; i__ <= *n; ++i__) {
        a_col_j[i__].r = 0.0;
        a_col_j[i__].i = 0.0;
    }
}
}
