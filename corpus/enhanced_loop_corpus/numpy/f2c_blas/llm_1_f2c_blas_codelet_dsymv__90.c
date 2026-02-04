#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
extern doublereal *alpha;
extern doublereal *a;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer *incy;
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
if (i__1 >= 1) {
    temp1 = *alpha * x[jx];
    temp2 = 0.;
    y[jy] += temp1 * a[1 + 1 * a_dim1];
    ix = jx;
    iy = jy;
    i__2 = *n;
    for (i__ = 2; i__ <= i__2; ++i__) {
        ix += *incx;
        iy += *incy;
        y[iy] += temp1 * a[i__ + 1 * a_dim1];
        temp2 += a[i__ + 1 * a_dim1] * x[ix];
    }
    y[jy] += *alpha * temp2;
    jx += *incx;
    jy += *incy;
}
for (j = 2; j <= i__1; ++j) {
    temp1 = *alpha * x[jx];
    temp2 = 0.;
    y[jy] += temp1 * a[j + j * a_dim1];
    ix = jx;
    iy = jy;
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        ix += *incx;
        iy += *incy;
        y[iy] += temp1 * a[i__ + j * a_dim1];
        temp2 += a[i__ + j * a_dim1] * x[ix];
    }
    y[jy] += *alpha * temp2;
    jx += *incx;
    jy += *incy;
}
}
