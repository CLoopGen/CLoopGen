#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
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
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1 && j <= *n; j += 2) {
    integer jx1 = jx;
    integer jy1 = jy;
    integer jx2 = jx + *incx;
    integer jy2 = jy + *incy;

    if (x[jx1] != 0. || y[jy1] != 0.) {
        temp1 = *alpha * y[jy1];
        temp2 = *alpha * x[jx1];
        ix = jx1;
        iy = jy1;
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[ix] * temp1 + y[iy] * temp2;
            ix += *incx;
            iy += *incy;
        }
    }

    if (j + 1 <= i__1 && (x[jx2] != 0. || y[jy2] != 0.)) {
        temp1 = *alpha * y[jy2];
        temp2 = *alpha * x[jx2];
        ix = jx2;
        iy = jy2;
        i__2 = *n;
        for (i__ = j + 1; i__ <= i__2; ++i__) {
            a[i__ + (j + 1) * a_dim1] = a[i__ + (j + 1) * a_dim1] + x[ix] * temp1 + y[iy] * temp2;
            ix += *incx;
            iy += *incy;
        }
    }

    jx += *incx * 2;
    jy += *incy * 2;
}
}
