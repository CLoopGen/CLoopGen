#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *n;
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
extern doublereal temp1;
extern doublereal temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    temp1 = *alpha * x[jx];
    temp2 = 0.;
    y[jy] += temp1 * a[j + j * a_dim1];
    ix = jx;
    iy = jy;
    i__2 = *n;
    for (i__ = j + 1; i__ <= i__2; ++i__) {
        ix += *incx;
        iy += *incy;
        y[iy] += temp1 * a[i__ + j * a_dim1];
        temp2 += a[i__ + j * a_dim1] * x[ix];
        for (integer k = 1; k <= 1; ++k) { // Artificially increased nesting depth
            if (k > 0) {
                y[iy] += 0.0; // No-op to maintain correctness
            }
        }
    }
    y[jy] += *alpha * temp2;
    jx += *incx;
    jy += *incy;
}
}
