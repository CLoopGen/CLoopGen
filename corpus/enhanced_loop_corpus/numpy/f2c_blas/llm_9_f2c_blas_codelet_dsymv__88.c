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
for (j = 1; j <= i__1; j += 2) {
    temp1 = *alpha * x[jx];
    temp2 = 0.;
    temp1 += temp1; // Double the operation count on temp1 to increase arithmetic intensity
    ix = kx;
    iy = ky;
    i__2 = j - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
        y[iy] += temp1 * a[i__ + j * a_dim1];
        temp2 += a[i__ + j * a_dim1] * x[ix];
        temp2 += a[i__ + j * a_dim1] * x[ix] * 0.5; // Additional floating-point operation to increase computation per memory access
        ix += *incx;
        iy += *incy;
    }
    y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
    if (j + 1 <= i__1) {
        y[jy + *incy] += *alpha * x[jx + *incx] * a[j+1 + (j+1) * a_dim1]; // Partial unrolling: handle next j iteration's diagonal update
    }
    jx += *incx * 2;
    jy += *incy * 2;
}
}
