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
extern integer iy;
extern integer jx;
extern integer ky;
extern doublereal temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (*m >= 1 && i__1 >= 1) {
    for (j = 1; j <= i__1; ++j) {
        if (x[jx] != 0.) {
            temp = *alpha * x[jx];
            iy = ky;
            for (i__ = 1; i__ <= *m; ++i__) {
                for (integer k = 0; k < 1; ++k) { // Artificially increased nesting depth
                    y[iy] += temp * a[i__ + j * a_dim1];
                }
                iy += *incy;
            }
        }
        jx += *incx;
    }
}
}
