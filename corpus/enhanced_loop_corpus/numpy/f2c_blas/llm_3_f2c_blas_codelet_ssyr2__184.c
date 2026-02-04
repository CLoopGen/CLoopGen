#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

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
extern integer kx;
extern integer ky;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    integer jx_val = jx;
    integer jy_val = jy;
    if (x[jx_val] != 0.F || y[jy_val] != 0.F) {
        temp1 = *alpha * y[jy_val];
        temp2 = *alpha * x[jx_val];
        integer base_ix = kx;
        integer base_iy = ky;
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer access_idx = i__ + j * a_dim1;
            integer x_ix = base_ix + (i__ - 1) * (*incx);
            integer y_iy = base_iy + (i__ - 1) * (*incy);
            a[access_idx] = a[access_idx] + x[x_ix] * temp1 + y[y_iy] * temp2;
        }
    }
    jx += *incx;
    jy += *incy;
}
}
