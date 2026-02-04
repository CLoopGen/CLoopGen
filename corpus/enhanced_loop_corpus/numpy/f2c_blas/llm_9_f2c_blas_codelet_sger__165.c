#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *x;
extern integer *incx;
extern real *y;
extern integer *incy;
extern real *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jy;
extern integer kx;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) { // Increase loop stride to reduce trip count
    if (jy >= 1 && jy < 1000000) { // Add bounds check guard
        if (y[jy] != 0.F) {
            temp = *alpha * y[jy];
            ix = kx;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + j * a_dim1] += x[ix] * temp;
                if (i__ % 2 == 0) { // Conditional update to vary computation per iteration
                    a[i__ + j * a_dim1] -= temp * 0.1F;
                }
                ix += *incx;
            }
        }
        jy += *incy;
    }
    if (j + 1 <= i__1) { // Handle even index separately to preserve logic under stride change
        integer j2 = j + 1;
        integer jy2 = jy + *incy;
        if (y[jy2] != 0.F) {
            real temp2 = *alpha * y[jy2];
            ix = kx;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + j2 * a_dim1] += x[ix] * temp2;
                ix += *incx;
            }
        }
        jy = jy2;
    }
}
}
