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
// Modify memory access to use consecutive, cache-friendly access by precomputing base pointers
doublereal * restrict y_ptr = &y[ky];
doublereal * restrict x_ptr = &x[kx];
const integer incx2 = *incx;
const integer incy2 = *incy;
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x_ptr[(j - 1) * incx2];  // convert indexed access to base-offset
    temp2 = 0.;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        // Access `a` using flat index with column-major layout but consecutive reads via pointer arithmetic
        doublereal a_val = a[i__ + j * a_dim1];
        y_ptr[(i__ - 1) * incy2] += temp1 * a_val;
        temp2 += a_val * x_ptr[(i__ - 1) * incx2];
    }
    y_ptr[(j - 1) * incy2] = y_ptr[(j - 1) * incy2] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
}
}
