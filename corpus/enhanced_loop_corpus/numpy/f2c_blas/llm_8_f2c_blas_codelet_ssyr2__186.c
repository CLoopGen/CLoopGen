#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
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
extern integer iy;
extern integer jx;
extern integer jy;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    if (x[jx] != 0.F || y[jy] != 0.F) {
        temp1 = *alpha * y[jy];
        temp2 = *alpha * x[jx];
        ix = jx;
        iy = jy;
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + x[ix] * temp1 + y[iy] * temp2;
            a[i__ + j * a_dim1] += x[ix + *incx] * temp1 + y[iy + *incy] * temp2;
            ix += *incx * 2;
            iy += *incy * 2;
        }
    }
    jx += *incx * 2;
    jy += *incy * 2;
}
}
