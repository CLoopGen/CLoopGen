#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
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
extern integer iy;
extern integer jx;
extern integer ky;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (*incx == 0 || *incy == 0) return;
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.F) {
            temp = *alpha * x[jx];
            iy = ky;
            i__2 = *m;
            for (integer k = 0; k < i__2; ++k) {
                i__ = k + 1;
                y[iy] += temp * a[i__ + j * a_dim1];
                iy += *incy;
            }
        }
        jx += *incx;
    }
}
