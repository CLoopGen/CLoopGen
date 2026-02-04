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
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t base_b_j = (j - 1) * b_dim1;
    ptrdiff_t base_a_i;
    for (i__ = *m; i__ >= 1; --i__) {
        ptrdiff_t idx_b = (i__ - 1) + base_b_j;
        temp = b[idx_b];
        if (nounit) {
            base_a_i = (i__ - 1) * (a_dim1 + 1);
            temp *= a[base_a_i];
        }
        i__2 = i__ - 1;
        for (k = 1; k <= i__2; ++k) {
            ptrdiff_t idx_a = (k - 1) + (i__ - 1) * a_dim1;
            ptrdiff_t idx_b_k = (k - 1) + base_b_j;
            temp += a[idx_a] * b[idx_b_k];
        }
        b[idx_b] = *alpha * temp;
    }
}
}
