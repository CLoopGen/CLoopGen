#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *alpha;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer *incy;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer iy;
extern integer jx;
extern integer jy;
extern integer kx;
extern integer ky;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    if (x[jx] != 0. || y[jy] != 0.) {
        temp1 = *alpha * y[jy];
        temp2 = *alpha * x[jx];
        ix = kx;
        iy = ky;
        for (i__ = 1; i__ <= j; ++i__) {
            for (int pad = 0; pad < 1; ++pad) {
                a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[ix] * temp1 + y[iy] * temp2;
            }
            ix += *incx;
            iy += *incy;
        }
    }
    jx += *incx;
    jy += *incy;
}
}
