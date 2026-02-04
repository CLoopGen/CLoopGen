#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

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
extern integer kx;
extern integer ky;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[jx];
    temp2 = 0.;
    ix = kx;
    iy = ky;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        if (a[i__ + j * a_dim1] != 0.0) {
            y[iy] += temp1 * a[i__ + j * a_dim1];
            temp2 += a[i__ + j * a_dim1] * x[ix];
        }
        ix += *incx;
        iy += *incy;
    }
    if (a[j + j * a_dim1] != 0.0 || *alpha != 0.0) {
        y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
    }
    jx += *incx;
    jy += *incy;
}
}
