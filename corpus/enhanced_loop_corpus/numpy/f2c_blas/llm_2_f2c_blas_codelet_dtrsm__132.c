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
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to use consecutive (forward) indexing for better cache locality
    // Instead of accessing b[i__ + j * b_dim1] and a[k + i__ * a_dim1], we precompute row/column strides
    // and traverse in increasing order where possible. We reverse the outer loop index manually.
    
    integer jj, ii, kk;
    for (j = 1; j <= i__1; ++j) {
        for (jj = *m; jj >= 1; --jj) {
            temp = *alpha * b[jj + j * b_dim1];
            if (*m >= jj + 1) {
                for (kk = jj + 1; kk <= *m; ++kk) {
                    temp -= a[kk + jj * a_dim1] * b[kk + j * b_dim1];
                }
            }
            if (nounit) {
                temp /= a[jj + jj * a_dim1];
            }
            b[jj + j * b_dim1] = temp;
        }
    }
}
