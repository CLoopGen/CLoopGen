#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *x;
extern real *y;
extern integer *incy;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer jy;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing y[jy] with strided increment via jy += *incy,
    // we precompute a consecutive array for y_vals and access it sequentially.
    // Assume an auxiliary array y_consec has been populated off-loop with the required values in order.
    real *y_consec = (real*)malloc(i__1 * sizeof(real));
    integer jy_temp = jy;
    for (integer idx = 0; idx < i__1; ++idx) {
        y_consec[idx] = y[jy_temp];
        jy_temp += *incy;
    }

    for (j = 1; j <= i__1; ++j) {
        if (y_consec[j - 1] != 0.F) {
            temp = *alpha * y_consec[j - 1];
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + j * a_dim1] += x[i__] * temp;
            }
        }
    }

    free(y_consec);
}
