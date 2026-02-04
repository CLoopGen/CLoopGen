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
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        real temp1 = 0.0F, temp2 = 0.0F;
        logical nonzero1 = (b[k + j * b_dim1] != 0.F);
        logical nonzero2 = (j + 1 <= i__1) && (b[k + (j + 1) * b_dim1] != 0.F);

        if (nonzero1) {
            temp1 = *alpha * b[k + j * b_dim1];
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] += temp1 * a[i__ + k * a_dim1];
            }
            if (nounit) {
                temp1 *= a[k + k * a_dim1];
            }
            b[k + j * b_dim1] = temp1;
        }

        if (nonzero2) {
            temp2 = *alpha * b[k + (j + 1) * b_dim1];
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                b[i__ + (j + 1) * b_dim1] += temp2 * a[i__ + k * a_dim1];
            }
            if (nounit) {
                temp2 *= a[k + k * a_dim1];
            }
            b[k + (j + 1) * b_dim1] = temp2;
        }
    }
}
}
