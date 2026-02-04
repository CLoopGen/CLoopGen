#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef int logical;

extern integer *m;
extern integer *n;
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
for (k = *n; k >= 1; --k) {
    i__1 = *n;
    for (j = k + 1; j <= i__1; ++j) {
        ptrdiff_t a_idx = j + k * a_dim1;
        ptrdiff_t b_j_base = j * b_dim1;
        ptrdiff_t b_k_base = k * b_dim1;
        if (a[a_idx] != 0.) {
            temp = *alpha * a[a_idx];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                ptrdiff_t b_i_j = i__ + b_j_base;
                ptrdiff_t b_i_k = i__ + b_k_base;
                b[b_i_j] += temp * b[b_i_k];
            }
        }
    }
    temp = *alpha;
    if (nounit) {
        temp *= a[k + k * a_dim1];
    }
    if (temp != 1.) {
        i__1 = *m;
        ptrdiff_t b_k_offset = k * b_dim1;
        for (i__ = 1; i__ <= i__1; ++i__) {
            ptrdiff_t b_i_k = i__ + b_k_offset;
            b[b_i_k] = temp * b[b_i_k];
        }
    }
}
}
