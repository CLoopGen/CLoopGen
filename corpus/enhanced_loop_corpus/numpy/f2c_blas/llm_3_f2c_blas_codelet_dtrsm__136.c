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
extern integer i__3;
extern integer i__;
extern integer j;
extern integer k;
extern doublereal temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 1; k <= i__1; ++k) {
    ptrdiff_t base_k_b = k * b_dim1;
    ptrdiff_t base_k_a = k * a_dim1;
    if (nounit) {
        temp = 1. / a[k + base_k_a];
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t idx_b = i__ + base_k_b;
            b[idx_b] = temp * b[idx_b];
        }
    }
    i__2 = *n;
    for (j = k + 1; j <= i__2; ++j) {
        ptrdiff_t addr_akj = j + k * a_dim1;
        if (a[addr_akj] != 0.) {
            temp = a[addr_akj];
            ptrdiff_t base_j_b = j * b_dim1;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                ptrdiff_t idx_i_k = i__ + base_k_b;
                ptrdiff_t idx_i_j = i__ + base_j_b;
                b[idx_i_j] -= temp * b[idx_i_k];
            }
        }
    }
    if (*alpha != 1.) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t idx_b = i__ + base_k_b;
            b[idx_b] = *alpha * b[idx_b];
        }
    }
}
}
