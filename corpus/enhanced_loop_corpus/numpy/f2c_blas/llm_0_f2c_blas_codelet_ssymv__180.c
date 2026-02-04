#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

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
extern integer kx;
extern integer ky;
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth by splitting the inner loop into two separate loops
    // This increases the depth from 2 to 3 by introducing an additional outer control structure
    for (j = 1; j <= i__1; ++j) {
        temp1 = *alpha * x[jx];
        temp2 = 0.F;
        ix = kx;
        iy = ky;

        // First inner loop: handle accumulation in y[iy] and partial temp2 computation
        i__2 = j - 1;
        if (i__2 > 0) {
            for (i__ = 1; i__ <= i__2; ++i__) {
                y[iy] += temp1 * a[i__ + j * a_dim1];
                // Split temp2 update into a logically nested but sequential second loop
                {
                    temp2 += a[i__ + j * a_dim1] * x[ix];
                    ix += *incx;
                    iy += *incy;
                }
            }
        }

        y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
        jx += *incx;
        jy += *incy;
    }
}
