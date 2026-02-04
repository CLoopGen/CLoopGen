#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

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
extern integer kx;
extern integer ky;
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t jx_offset = (jx - 1);
    ptrdiff_t jy_offset = (jy - 1);
    if (x[jx_offset + 1] != 0. || y[jy_offset + 1] != 0.) {
        temp1 = *alpha * y[jy_offset + 1];
        temp2 = *alpha * x[jx_offset + 1];
        ptrdiff_t ix_offset = (kx - 1);
        ptrdiff_t iy_offset = (ky - 1);
        i__2 = j;
        for (i__ = 1; i__ <= i__2; ++i__) {
            ptrdiff_t a_index = (i__ + j * a_dim1) - 1;
            ptrdiff_t x_index = ix_offset + 1;
            ptrdiff_t y_index = iy_offset + 1;
            a[a_index] = a[a_index] + x[x_index] * temp1 + y[y_index] * temp2;
            ix_offset += *incx;
            iy_offset += *incy;
        }
    }
    jx += *incx;
    jy += *incy;
}
}
