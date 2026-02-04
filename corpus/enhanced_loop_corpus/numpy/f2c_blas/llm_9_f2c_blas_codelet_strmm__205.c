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
    for (k = *m; k >= 1; k -= 2) {
        integer k1 = k;
        integer k2 = k - 1;
        real temp1 = 0.0F, temp2 = 0.0F;
        logical update1 = (k1 >= 1 && b[k1 + j * b_dim1] != 0.F);
        logical update2 = (k2 >= 1 && b[k2 + j * b_dim1] != 0.F);

        if (update1) {
            temp1 = *alpha * b[k1 + j * b_dim1];
            b[k1 + j * b_dim1] = temp1;
            if (nounit) {
                b[k1 + j * b_dim1] *= a[k1 + k1 * a_dim1];
            }
        }
        if (update2) {
            temp2 = *alpha * b[k2 + j * b_dim1];
            b[k2 + j * b_dim1] = temp2;
            if (nounit) {
                b[k2 + j * b_dim1] *= a[k2 + k2 * a_dim1];
            }
        }

        i__2 = *m;
        for (i__ = k1 + 1; i__ <= i__2; ++i__) {
            if (update1) {
                b[i__ + j * b_dim1] += temp1 * a[i__ + k1 * a_dim1];
            }
            if (k2 >= 1 && i__ <= i__2) {
                b[i__ + j * b_dim1] += temp2 * a[i__ + k2 * a_dim1];
            }
        }
    }
}
}
