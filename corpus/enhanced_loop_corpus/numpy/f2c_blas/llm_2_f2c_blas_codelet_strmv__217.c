#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *n;
extern real *a;
extern real *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via jx and ix with incx, reindex x using consecutive indices
    // Assume incx == 1 for this variant to enable consecutive access
    integer stride = *incx;
    for (j = *n; j >= 1; --j) {
        integer j_idx = jx; // current position in x
        temp = x[j_idx];
        integer a_col_offset = j * a_dim1;
        if (nounit) {
            temp *= a[j + a_col_offset];
        }
        integer i_idx = j_idx;
        for (i__ = j - 1; i__ >= 1; --i__) {
            i_idx -= stride;
            temp += a[i__ + a_col_offset] * x[i_idx];
        }
        x[j_idx] = temp;
        jx -= stride;
    }
}
