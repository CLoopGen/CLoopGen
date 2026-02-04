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
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        ptrdiff_t idx_b_ij = (i__ - 1) + (j - 1) * b_dim1;
        temp = b[idx_b_ij];
        if (nounit) {
            ptrdiff_t idx_a_ii = (i__ - 1) + (i__ - 1) * a_dim1;
            temp *= a[idx_a_ii];
        }
        i__3 = *m;
        for (k = i__ + 1; k <= i__3; ++k) {
            ptrdiff_t idx_a_ki = (k - 1) + (i__ - 1) * a_dim1;
            ptrdiff_t idx_b_kj = (k - 1) + (j - 1) * b_dim1;
            temp += a[idx_a_ki] * b[idx_b_kj];
        }
        b[idx_b_ij] = *alpha * temp;
    }
}
}
