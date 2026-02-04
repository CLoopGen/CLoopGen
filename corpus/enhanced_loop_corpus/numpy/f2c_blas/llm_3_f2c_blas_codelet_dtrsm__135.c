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
    ptrdiff_t base_k_a = k * a_dim1;
    ptrdiff_t base_k_b = k * b_dim1;
    if (nounit) {
        temp = 1. / a[k + base_k_a];
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + base_k_b] = temp * b[i__ + base_k_b];
        }
    }
    i__1 = k - 1;
    for (j = 1; j <= i__1; ++j) {
        ptrdiff_t idx_a = j + base_k_a;
        if (a[idx_a] != 0.) {
            temp = a[idx_a];
            ptrdiff_t base_j_b = j * b_dim1;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + base_j_b] -= temp * b[i__ + base_k_b];
            }
        }
    }
    if (*alpha != 1.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + base_k_b] = *alpha * b[i__ + base_k_b];
        }
    }
}
}
