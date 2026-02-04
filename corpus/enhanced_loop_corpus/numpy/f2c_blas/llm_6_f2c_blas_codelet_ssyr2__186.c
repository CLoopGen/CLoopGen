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
    real temp1_local, temp2_local;
    integer ix_local, iy_local;
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.F || y[jy] != 0.F) {
            temp1_local = *alpha * y[jy];
            temp2_local = *alpha * x[jx];
            ix_local = jx;
            iy_local = jy;
            i__2 = *n;
            for (i__ = j; i__ <= i__2; ++i__) {
                real update = x[ix_local] * temp1_local + y[iy_local] * temp2_local;
                a[i__ + j * a_dim1] += update;
                ix_local += *incx;
                iy_local += *incy;
            }
        }
        jx += *incx;
        jy += *incy;
    }
}
