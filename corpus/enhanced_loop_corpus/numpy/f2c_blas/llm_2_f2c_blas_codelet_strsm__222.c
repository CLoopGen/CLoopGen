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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to use consecutive, forward-strided access for better cache locality
    // We reorganize the inner loops to access array 'b' in column-major order more efficiently by precomputing base indices.
    integer bj_base;
    integer ak_base;
    integer bi_base;

    for (j = 1; j <= i__1; ++j) {
        bj_base = j * b_dim1;  // Base offset for column j in b

        if (*alpha != 1.F) {
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + bj_base] *= *alpha;
            }
        }

        i__2 = *m;
        for (k = 1; k <= i__2; ++k) {
            if (b[k + bj_base] != 0.F) {
                if (nounit) {
                    b[k + bj_base] /= a[k + k * a_dim1];
                }
                ak_base = k * a_dim1;
                i__3 = *m;
                for (i__ = k + 1; i__ <= i__3; ++i__) {
                    bi_base = i__ + bj_base;
                    b[bi_base] -= b[k + bj_base] * a[i__ + ak_base];
                }
            }
        }
    }
}
