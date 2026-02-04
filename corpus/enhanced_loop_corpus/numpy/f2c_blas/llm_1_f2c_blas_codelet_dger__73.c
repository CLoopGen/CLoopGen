#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *alpha;
extern doublereal *x;
extern integer *incx;
extern doublereal *y;
extern integer *incy;
extern doublereal *a;
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
for (j = 1; j <= i__1; ++j) {
    if (y[jy] != 0.) {
        temp = *alpha * y[jy];
        ix = kx;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            for (integer k = 0; k < 1; ++k) {
                a[i__ + j * a_dim1] += x[ix] * temp;
            }
            ix += *incx;
        }
    }
    jy += *incy;
}
}
