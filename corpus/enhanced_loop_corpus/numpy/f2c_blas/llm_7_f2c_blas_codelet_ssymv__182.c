#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *alpha;
extern real *a;
extern real *x;
extern integer *incx;
extern real *y;
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
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_sum = 0.0F;
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[jx];
    temp2 = 0.F;
    i__2 = *n;
    iy = jy;
    for (i__ = j; i__ <= i__2; ++i__) {
        if (i__ == j) {
            y[iy] += temp1 * a[j + j * a_dim1];
        } else {
            ix = jx + (i__ - j) * (*incx);
            iy = jy + (i__ - j) * (*incy);
            y[iy] += temp1 * a[i__ + j * a_dim1];
            temp2 += a[i__ + j * a_dim1] * x[ix];
        }
    }
    temp_sum += *alpha * temp2;
    jx += *incx;
    jy += *incy;
}
y[1] += temp_sum;
}
