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
for (j = 1; j <= i__1; ++j) {
    integer offset_x = (j - 1) * (*incx);
    integer offset_y = (j - 1) * (*incy);
    if (x[1 + offset_x] != 0. || y[1 + offset_y] != 0.) {
        temp1 = *alpha * y[1 + offset_y];
        temp2 = *alpha * x[1 + offset_x];
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            integer idx_a = i__ + j * a_dim1;
            integer idx_x = 1 + offset_x + (i__ - j) * (*incx);
            integer idx_y = 1 + offset_y + (i__ - j) * (*incy);
            a[idx_a] = a[idx_a] + x[idx_x] * temp1 + y[idx_y] * temp2;
        }
    }
}
}
