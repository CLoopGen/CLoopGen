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
        // Change to strided access with explicit stride on `a` and reverse traversal on `x`
        y[iy] += temp1 * a[(j * a_dim1 + i__)];  // row-major access pattern
        temp2 += a[(j * a_dim1 + i__)] * x[ix];
        ix += (*incx << 1);  // double the increment stride for x
        iy += *incy;
    }
    y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
    jx += *incx;
    jy += *incy;
}
}
