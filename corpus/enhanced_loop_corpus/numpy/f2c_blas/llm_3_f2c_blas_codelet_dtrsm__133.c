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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t bj_offset = (j - 1) * b_dim1;
    if (*alpha != 1.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t idx = (i__ - 1) + bj_offset;
            b[idx] = *alpha * b[idx];
        }
    }
    i__2 = j - 1;
    for (k = 1; k <= i__2; ++k) {
        ptrdiff_t akj_offset = (k - 1) + (j - 1) * a_dim1;
        if (a[akj_offset] != 0.) {
            ptrdiff_t bk_offset = (k - 1) * b_dim1;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                ptrdiff_t bi_j = (i__ - 1) + bj_offset;
                ptrdiff_t bi_k = (i__ - 1) + bk_offset;
                b[bi_j] -= a[akj_offset] * b[bi_k];
            }
        }
    }
    if (nounit) {
        temp = 1. / a[(j - 1) + (j - 1) * a_dim1];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t idx = (i__ - 1) + bj_offset;
            b[idx] = temp * b[idx];
        }
    }
}
}
