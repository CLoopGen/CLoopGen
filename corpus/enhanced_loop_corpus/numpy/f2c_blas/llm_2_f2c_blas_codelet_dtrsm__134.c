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
// Variant 1: Modify memory access pattern to use consecutive pointer arithmetic for array 'b'
// Instead of using indexed access (b[i__ + j * b_dim1]), we precompute the base address of column j and incrementally access elements.
doublereal *base_b_j;
doublereal *base_b_k;
for (j = *n; j >= 1; --j) {
    base_b_j = &b[j * b_dim1]; // Base pointer for column j of matrix b

    if (*alpha != 1.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            base_b_j[i__] = *alpha * base_b_j[i__];
        }
    }

    i__1 = *n;
    for (k = j + 1; k <= i__1; ++k) {
        if (a[k + j * a_dim1] != 0.) {
            base_b_k = &b[k * b_dim1]; // Base pointer for column k of matrix b
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                base_b_j[i__] -= a[k + j * a_dim1] * base_b_k[i__];
            }
        }
    }

    if (nounit) {
        temp = 1. / a[j + j * a_dim1];
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            base_b_j[i__] = temp * base_b_j[i__];
        }
    }
}
}
