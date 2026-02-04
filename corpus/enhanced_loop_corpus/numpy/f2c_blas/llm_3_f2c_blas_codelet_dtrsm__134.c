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
// Variant 2: Use strided memory access with explicit stride scaling
// Instead of relying on compiler interpretation of 2D indexing, simulate fixed stride access
// Assume b_dim1 and a_dim1 are known strides; access elements using scaled index
integer idx_b_j, idx_b_k, idx_a_kj, idx_ajj;
for (j = *n; j >= 1; --j) {
    idx_b_j = j * b_dim1;  // Column start index in b
    idx_ajj = j * a_dim1 + j; // Diagonal element a[j,j]

    if (*alpha != 1.) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + idx_b_j] = *alpha * b[i__ + idx_b_j];
        }
    }

    i__1 = *n;
    for (k = j + 1; k <= i__1; ++k) {
        idx_a_kj = k + j * a_dim1; // Index of a[k,j]
        if (a[idx_a_kj] != 0.) {
            idx_b_k = k * b_dim1; // Column k base in b
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + idx_b_j] -= a[idx_a_kj] * b[i__ + idx_b_k];
            }
        }
    }

    if (nounit) {
        temp = 1. / a[idx_ajj];
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + idx_b_j] = temp * b[i__ + idx_b_j];
        }
    }
}
}
