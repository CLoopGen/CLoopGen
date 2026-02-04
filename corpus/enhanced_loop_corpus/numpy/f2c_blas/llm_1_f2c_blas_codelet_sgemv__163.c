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
extern integer ix;
extern integer jy;
extern integer kx;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i__1 >= 1 && *m >= 1) {
        temp = 0.F;
        ix = kx;
        for (j = 1; j <= i__1; ++j) {
            temp = 0.F;
            int base_j = j * a_dim1;
            for (i__ = 1; i__ <= *m; ++i__) {
                temp += a[i__ + base_j] * x[ix];
                ix += *incx;
            }
            y[jy] += *alpha * temp;
            jy += *incy;
            kx += *incx; // Update kx if incx affects next column's start
            ix = kx;
        }
    }
}
