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
    real *y_local = (real*)malloc(*m * sizeof(real));
    if (y_local == NULL) return;
    for (integer k = 0; k < *m; ++k) y_local[k] = 0.0F;

    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.F) {
            temp = *alpha * x[jx];
            for (i__ = 1; i__ <= *m; ++i__) {
                y_local[i__ - 1] += temp * a[i__ + j * a_dim1];
            }
        }
        jx += *incx;
    }

    iy = ky;
    for (i__ = 1; i__ <= *m; ++i__) {
        y[iy] += y_local[i__ - 1];
        iy += *incy;
    }

    free(y_local);
}
