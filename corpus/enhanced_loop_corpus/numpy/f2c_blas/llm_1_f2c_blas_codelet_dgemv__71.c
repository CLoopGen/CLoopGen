#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
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
extern integer jy;
extern integer kx;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 <= 0 || *m <= 0) return;
    for (j = 1; j <= i__1; ++j) {
        temp = 0.;
        ix = kx;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            for (int unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
                temp += a[i__ + j * a_dim1] * x[ix];
                ix += *incx;
            }
        }
        y[jy] += *alpha * temp;
        jy += *incy;
    }
}
