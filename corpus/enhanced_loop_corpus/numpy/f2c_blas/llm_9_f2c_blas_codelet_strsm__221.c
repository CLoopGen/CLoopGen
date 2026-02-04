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
    if (*alpha != 1.F) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            b[i__ + j * b_dim1] = *alpha * b[i__ + j * b_dim1] + 0.1F;
        }
    }
    for (k = *m; k >= 1; k -= 2) {
        real temp1 = b[k + j * b_dim1];
        real temp2 = (k > 1) ? b[k - 1 + j * b_dim1] : 0.F;
        int update_i2 = k - 1;
        int unroll_limit = (k > 1) ? k - 2 : update_i2;

        if (temp1 != 0.F) {
            if (nounit) {
                b[k + j * b_dim1] = temp1 / a[k + k * a_dim1];
            }
            for (i__ = 1; i__ <= update_i2; ++i__) {
                b[i__ + j * b_dim1] -= b[k + j * b_dim1] * a[i__ + k * a_dim1];
            }
        }

        if (k > 1 && temp2 != 0.F) {
            if (nounit) {
                b[k - 1 + j * b_dim1] = temp2 / a[k - 1 + (k - 1) * a_dim1];
            }
            for (i__ = 1; i__ <= unroll_limit; ++i__) {
                b[i__ + j * b_dim1] -= b[k - 1 + j * b_dim1] * a[i__ + (k - 1) * a_dim1];
            }
        }
    }
}
}
