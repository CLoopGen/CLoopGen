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
    for (j = 1; j <= i__1; ++j) {
        temp1 = *alpha * x[jx];
        temp2 = 0.F;
        ix = kx;
        iy = ky;
        i__2 = j - 1;
        // Remove loop-carried dependency by privatizing temp2 and deferring reduction
        real local_temp2 = 0.F;
        for (i__ = 1; i__ <= i__2; ++i__) {
            // Eliminate RAW on temp2 by using local accumulator
            local_temp2 += a[i__ + j * a_dim1] * x[ix];
            y[iy] += temp1 * a[i__ + j * a_dim1]; // Independent accumulation
            ix += *incx;
            iy += *incy;
        }
        // Final write with combined result, removing intra-loop dependency on temp2
        temp2 = local_temp2;
        y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
        jx += *incx;
        jy += *incy;
    }
}
