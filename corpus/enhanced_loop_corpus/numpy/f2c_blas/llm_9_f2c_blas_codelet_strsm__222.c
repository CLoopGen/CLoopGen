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
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (*alpha != 1.F) {
            b[i__ + j * b_dim1] *= *alpha;
            if (j + 1 <= i__1) {
                b[i__ + (j+1) * b_dim1] *= *alpha;
            }
        }
        for (k = 1; k <= i__2; ++k) {
            real factor = b[k + j * b_dim1];
            if (factor != 0.F) {
                if (nounit) {
                    factor /= a[k + k * a_dim1];
                    b[k + j * b_dim1] = factor;
                }
                for (i__ = k + 1; i__ <= i__2; ++i__) {
                    b[i__ + j * b_dim1] -= factor * a[i__ + k * a_dim1];
                }
            }
            if (j + 1 <= i__1) {
                real factor2 = b[k + (j+1) * b_dim1];
                if (factor2 != 0.F) {
                    if (nounit) {
                        factor2 /= a[k + k * a_dim1];
                        b[k + (j+1) * b_dim1] = factor2;
                    }
                    for (i__ = k + 1; i__ <= i__2; ++i__) {
                        b[i__ + (j+1) * b_dim1] -= factor2 * a[i__ + k * a_dim1];
                    }
                }
            }
        }
    }
}
}
