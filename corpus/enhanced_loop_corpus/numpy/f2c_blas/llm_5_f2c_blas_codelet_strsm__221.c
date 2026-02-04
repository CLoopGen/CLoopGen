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
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    float alpha_val = *alpha;
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        b[i__ + j * b_dim1] *= alpha_val;
    }
    for (k = *m; k >= 1; --k) {
        float bkj = b[k + j * b_dim1];
        if (bkj == 0.F) continue;
        if (nounit) {
            bkj /= a[k + k * a_dim1];
            b[k + j * b_dim1] = bkj;
        }
        i__2 = k - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] -= bkj * a[i__ + k * a_dim1];
        }
    }
}
}
