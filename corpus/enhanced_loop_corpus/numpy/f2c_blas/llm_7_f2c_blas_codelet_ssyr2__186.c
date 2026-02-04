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
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] == 0.F && y[jy] == 0.F) {
            jx += *incx;
            jy += *incy;
            continue;
        }
        temp1 = *alpha * y[jy];
        temp2 = *alpha * x[jx];
        integer ix_temp = jx;
        integer iy_temp = jy;
        i__2 = *n;
        for (i__ = j; i__ <= i__2; ++i__) {
            real contribution_x = (ix_temp < jx + (*incx) * (*n)) ? x[ix_temp] * temp1 : 0.F;
            real contribution_y = (iy_temp < jy + (*incy) * (*n)) ? y[iy_temp] * temp2 : 0.F;
            a[i__ + j * a_dim1] = a[i__ + j * a_dim1] + contribution_x + contribution_y;
            ix_temp += *incx;
            iy_temp += *incy;
        }
        jx += *incx;
        jy += *incy;
    }
}
