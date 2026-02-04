#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
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
extern real temp1;
extern real temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Modify strided access (via jx, jy, ix, iy) to use consecutive indexing by removing indirection and accessing x and y directly with unit stride.
    // Assume incx = 1 and incy = 1 for consecutive access.
    integer i, j;
    real temp1, temp2;
    for (j = 0; j < i__1; ++j) {
        temp1 = *alpha * x[j];
        temp2 = 0.0F;
        y[j] += temp1 * a[j + j * a_dim1];
        i__2 = *n;
        for (i = j + 1; i < i__2; ++i) {
            y[i] += temp1 * a[i + j * a_dim1];
            temp2 += a[i + j * a_dim1] * x[i];
        }
        y[j] += *alpha * temp2;
    }
}
