#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *m;
extern doublecomplex *alpha;
extern doublecomplex *a;
extern doublecomplex *x;
extern integer *incx;
extern doublecomplex *y;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer jx;
extern doublecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    integer temp_index = jx;
    doublecomplex local_temp = {0.0, 0.0};

    if (x[temp_index].r != 0. || x[temp_index].i != 0.) {
        z__1.r = alpha->r * x[temp_index].r - alpha->i * x[temp_index].i;
        z__1.i = alpha->r * x[temp_index].i + alpha->i * x[temp_index].r;
        local_temp = z__1;

        for (i__ = *m; i__ >= 1; --i__) {
            integer a_index = i__ + j * a_dim1;
            integer y_index = i__;

            z__2.r = local_temp.r * a[a_index].r - local_temp.i * a[a_index].i;
            z__2.i = local_temp.r * a[a_index].i + local_temp.i * a[a_index].r;

            y[y_index].r = y[y_index].r + z__2.r;
            y[y_index].i = y[y_index].i + z__2.i;
        }
    }
    jx += *incx;
}
}
