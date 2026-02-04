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
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t bj_offset = j * b_dim1;
    if (*alpha != 1.F) {
        i__2 = *m;
        real alpha_val = *alpha;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t index = i__ + bj_offset;
            b[index] = alpha_val * b[index];
        }
    }
    i__2 = j - 1;
    for (k = 1; k <= i__2; ++k) {
        ptrdiff_t akj_index = k + j * a_dim1;
        if (a[akj_index] != 0.F) {
            real a_val = a[akj_index];
            i__3 = *m;
            ptrdiff_t bk_offset = k * b_dim1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                ptrdiff_t bij_index = i__ + bj_offset;
                ptrdiff_t bik_index = i__ + bk_offset;
                b[bij_index] -= a_val * b[bik_index];
            }
        }
    }
    if (nounit) {
        ptrdiff_t ajj_index = j + j * a_dim1;
        temp = 1.F / a[ajj_index];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t index = i__ + bj_offset;
            b[index] = temp * b[index];
        }
    }
}
}
