#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *m;
extern real *alpha;
extern real *x;
extern integer *incx;
extern real *y;
extern integer *incy;
extern real *a;
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
for (j = 1; j <= i__1; ++j) {
    integer y_index = jy;
    if (y[y_index] != 0.F) {
        temp = *alpha * y[y_index];
        integer base_x_index = kx;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            integer a_index = i__ + j * a_dim1;
            integer x_index = base_x_index + (i__ - 1) * (*incx);
            a[a_index] += x[x_index] * temp;
        }
    }
    jy += *incy;
}
}
