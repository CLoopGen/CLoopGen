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
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[jx];
    temp2 = 0.;
    ix = jx;
    iy = jy;
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        ix += *incx;
        iy += *incy;
        temp2 += a[i__ + j * a_dim1] * x[ix];
        y[iy] = y[iy] + temp1 * a[i__ + j * a_dim1]; // Reordered computation: use updated temp2 later
    }
    // Introduce artificial dependency: scale temp2 with a function of j to break direct WAW on y[jy]
    temp2 *= (doublereal)(j % 7 + 1);
    y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
    jx += *incx;
    jy += *incy;
}
}
