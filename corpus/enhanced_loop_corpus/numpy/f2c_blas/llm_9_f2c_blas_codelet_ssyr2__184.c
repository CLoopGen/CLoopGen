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
for (j = 1; j <= i__1; j += 2) {
    for (integer offset = 0; offset < 2 && (j + offset) <= i__1; ++offset) {
        integer current_j = j + offset;
        integer current_jx = jx + offset * (*incx);
        integer current_jy = jy + offset * (*incy);
        if (x[current_jx] != 0.F || y[current_jy] != 0.F) {
            temp1 = *alpha * y[current_jy];
            temp2 = *alpha * x[current_jx];
            ix = kx;
            iy = ky;
            i__2 = current_j;
            for (i__ = 1; i__ <= i__2; ++i__) {
                a[i__ + current_j * a_dim1] = a[i__ + current_j * a_dim1] + x[ix] * temp1 + y[iy] * temp2;
                ix += *incx;
                iy += *incy;
            }
        }
    }
    jx += 2 * (*incx);
    jy += 2 * (*incy);
}
}
