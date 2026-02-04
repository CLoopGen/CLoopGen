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
for (j = 1; j <= i__1; ++j) {
    for (i__ = *m; i__ >= 1; --i__) {
        ptrdiff_t b_idx_ij = (i__ - 1) + (j - 1) * b_dim1;
        temp = b[b_idx_ij];
        if (nounit) {
            ptrdiff_t a_diag_ii = (i__ - 1) + (i__ - 1) * a_dim1;
            temp *= a[a_diag_ii];
        }
        i__2 = i__ - 1;
        for (k = 1; k <= i__2; ++k) {
            ptrdiff_t a_idx_ki = (k - 1) + (i__ - 1) * a_dim1;
            ptrdiff_t b_idx_kj = (k - 1) + (j - 1) * b_dim1;
            temp += a[a_idx_ki] * b[b_idx_kj];
        }
        b[b_idx_ij] = *alpha * temp;
    }
}
}
