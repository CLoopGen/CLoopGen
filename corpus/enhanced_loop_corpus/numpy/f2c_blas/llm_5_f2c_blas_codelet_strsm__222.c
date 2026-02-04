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
for (j = 1; j <= i__1; ++j) {
    int alpha_factor = (*alpha == 1.F);
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (!alpha_factor) {
            b[i__ + j * b_dim1] = *alpha * b[i__ + j * b_dim1];
        }
    }
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        real value = b[k + j * b_dim1];
        int is_nonzero = (value != 0.F);
        if (is_nonzero && nounit) {
            value = b[k + j * b_dim1] = value / a[k + k * a_dim1];
        }
        if (is_nonzero) {
            i__3 = *m;
            for (i__ = k + 1; i__ <= i__3; ++i__) {
                b[i__ + j * b_dim1] -= value * a[i__ + k * a_dim1];
            }
        }
    }
}
}
