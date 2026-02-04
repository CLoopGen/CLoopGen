#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern real *alpha;
extern real *a;
extern real *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer k;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t b_col_offset = (j - 1) * b_dim1;
    ptrdiff_t a_col_offset, b_k_index;
    if (*alpha != 1.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + b_col_offset] = *alpha * b[i__ + b_col_offset];
        }
    }
    for (k = *m; k >= 1; --k) {
        b_k_index = k + b_col_offset;
        if (b[b_k_index] != 0.F) {
            if (nounit) {
                b[b_k_index] /= a[k + k * a_dim1];
            }
            a_col_offset = (k - 1) * a_dim1;
            i__2 = k - 1;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + b_col_offset] -= b[b_k_index] * a[i__ + a_col_offset];
            }
        }
    }
}
}
