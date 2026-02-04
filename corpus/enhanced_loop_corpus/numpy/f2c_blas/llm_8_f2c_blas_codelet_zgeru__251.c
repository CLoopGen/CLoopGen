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
extern doublecomplex *x;
extern doublecomplex *y;
extern integer *incy;
extern doublecomplex *a;
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
extern integer jy;
extern doublecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
integer temp_r_exists = 0;
doublecomplex local_temp;
for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    temp_r_exists = (y[i__2].r != 0. || y[i__2].i != 0.);
    if (temp_r_exists) {
        i__2 = jy;
        z__1.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i;
        z__1.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        local_temp.r = z__1.r;
        local_temp.i = z__1.i;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__5 = i__;
            i__3 = i__ + j * a_dim1;
            z__2.r = x[i__5].r * local_temp.r - x[i__5].i * local_temp.i;
            z__2.i = x[i__5].r * local_temp.i + x[i__5].i * local_temp.r;
            a[i__3].r += z__2.r;
            a[i__3].i += z__2.i;
        }
    }
    jy += *incy;
}
}
