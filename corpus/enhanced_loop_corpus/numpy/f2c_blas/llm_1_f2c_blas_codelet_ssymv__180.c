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
    // Variant 2: Decreased loop nesting depth by flattening the inner loop logic
    // The original two-level nest is reduced in conceptual depth by merging loop bounds
    // and using conditional execution within a single loop over all possible indices
    integer total_iterations = 0;
    for (j = 1; j <= i__1; ++j) {
        total_iterations += (j > 1) ? (j - 1) : 0;
    }

    // Simulate nested behavior with one loop and manual index tracking
    integer flat_i = 0;
    j = 1;
    integer remaining = (i__1 >= 1) ? (j <= i__1 ? j - 1 : 0) : 0;
    integer current_j_start = 1;

    for (flat_i = 1; flat_i <= total_iterations; ++flat_i) {
        if (remaining == 0) {
            // Advance to next j
            ++j;
            temp1 = *alpha * x[kx + (j - 1) * (*incx)]; // approximate jx
            temp2 = 0.0F;
            ix = kx;
            iy = ky;
            i__2 = j - 1;
            remaining = i__2;
            current_j_start = flat_i;
        }

        i__ = flat_i - current_j_start + 1;

        y[iy] += temp1 * a[i__ + j * a_dim1];
        temp2 += a[i__ + j * a_dim1] * x[ix];

        ix += *incx;
        iy += *incy;
        --remaining;

        // After processing last i for this j, finalize y[jy]
        if (remaining == 0) {
            jx = kx + (j - 1) * (*incx);
            jy = ky + (j - 1) * (*incy);
            y[jy] = y[jy] + temp1 * a[j + j * a_dim1] + *alpha * temp2;
        }
    }

    // Handle case when i__1 == 0 or no inner iterations occurred
    if (i__1 == 0) {
        j = 1;
        for (; j <= i__1; ++j) {
            temp1 = *alpha * x[jx];
            y[jy] = y[jy] + temp1 * a[j + j * a_dim1];
            jx += *incx;
            jy += *incy;
        }
    }
}
