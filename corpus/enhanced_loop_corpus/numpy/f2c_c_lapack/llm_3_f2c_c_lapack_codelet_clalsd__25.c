#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *n;
extern singlecomplex *b;
extern real *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer jcol;
extern integer jrow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Stride
    // Instead of iterating sequentially over columns first, we access every other column
    // (stride of 2), then handle remaining elements if needed. This creates a strided pattern.
    // Only even-indexed jcol are processed in this version for mutation effect.
    integer stride = 2;
    i__2 = *n;
    for (jcol = 1; jcol <= i__1; jcol += stride) {
        for (jrow = 1; jrow <= i__2; ++jrow) {
            ++j;
            i__3 = jrow + jcol * b_dim1;
            rwork[j] = b[i__3].r;
        }
    }
    // Complete remaining columns if i__1 is odd (to preserve functionality approximately)
    for (jcol = 2; jcol <= i__1; jcol += stride) {
        for (jrow = 1; jrow <= i__2; ++jrow) {
            ++j;
            i__3 = jrow + jcol * b_dim1;
            rwork[j] = b[i__3].r;
        }
    }
}
