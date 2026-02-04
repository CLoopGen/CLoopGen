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
extern integer i__;
extern integer j;
extern integer k;
extern real temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = *n; k >= 1; --k) {
    ptrdiff_t base_k_a = k * a_dim1;
    ptrdiff_t base_k_b = k * b_dim1;
    i__1 = *n;
    for (j = k + 1; j <= i__1; ++j) {
        ptrdiff_t idx_aj = j + base_k_a;
        if (a[idx_aj] != 0.F) {
            temp = *alpha * a[idx_aj];
            ptrdiff_t idx_j_b = j * b_dim1;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                b[i__ + idx_j_b] += temp * b[i__ + base_k_b];
            }
        }
    }
    temp = *alpha;
    if (nounit) {
        temp *= a[k + base_k_a];
    }
    if (temp != 1.F) {
        i__1 = *m;
        for (i__ = 1; i__ <= i__1; ++i__) {
            b[i__ + base_k_b] = temp * b[i__ + base_k_b];
        }
    }
}
}
