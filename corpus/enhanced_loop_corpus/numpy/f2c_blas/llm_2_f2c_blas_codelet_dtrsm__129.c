#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *b;
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
    // Variant 1: Change memory access pattern to use consecutive indexing with pointer arithmetic
    // Instead of using row-major indexing with strides, we precompute base pointers for each column j
    // and traverse b and a arrays using consecutive increments for better spatial locality.

    integer j_start = 1;
    integer j_end = i__1;
    doublereal alpha_val = *alpha;
    logical nounit_flag = nounit;
    integer m_val = *m;

    for (j = j_start; j <= j_end; ++j) {
        doublereal *b_col = &b[j * b_dim1];  // Base pointer for column j of B
        const doublereal *a_ptr;

        if (alpha_val != 1.0) {
            for (i__ = 1; i__ <= m_val; ++i__) {
                b_col[i__] *= alpha_val;
            }
        }

        for (k = m_val; k >= 1; --k) {
            doublereal b_kj = b_col[k];
            if (b_kj != 0.0) {
                if (nounit_flag) {
                    b_kj /= a[k + k * a_dim1];
                    b_col[k] = b_kj;  // Update after division
                }
                a_ptr = &a[k * a_dim1];  // Row k of A, accessed as base
                for (i__ = 1; i__ <= k - 1; ++i__) {
                    b_col[i__] -= b_kj * a_ptr[i__];  // Consecutive access in row k of A
                }
            }
        }
    }
}
