#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef int logical;

extern integer *m;
extern integer *n;
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
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= i__1; ++k) {
    ptrdiff_t ak_offset = k + k * a_dim1;
    ptrdiff_t bk_offset = k * b_dim1;
    if (nounit) {
        temp = 1.F / a[ak_offset];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t bi_offset = i__ + bk_offset;
            b[bi_offset] = temp * b[bi_offset];
        }
    }
    i__2 = *n;
    for (j = k + 1; j <= i__2; ++j) {
        ptrdiff_t ajk_offset = j + k * a_dim1;
        if (a[ajk_offset] != 0.F) {
            temp = a[ajk_offset];
            ptrdiff_t bj_offset = j * b_dim1;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                ptrdiff_t bi_j_offset = i__ + bj_offset;
                ptrdiff_t bi_k_offset = i__ + bk_offset;
                b[bi_j_offset] -= temp * b[bi_k_offset];
            }
        }
    }
    if (*alpha != 1.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t bi_offset = i__ + bk_offset;
            b[bi_offset] = *alpha * b[bi_offset];
        }
    }
}
}
