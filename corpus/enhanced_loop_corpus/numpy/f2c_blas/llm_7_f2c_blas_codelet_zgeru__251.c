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
for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    if (y[i__2].r != 0. || y[i__2].i != 0.) {
        i__2 = jy;
        z__1.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i , z__1.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        temp.r = z__1.r , temp.i = z__1.i;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            i__4 = i__ + j * a_dim1;
            i__5 = i__;
            z__2.r = x[i__5].r * temp.r - x[i__5].i * temp.i , z__2.i = x[i__5].r * temp.i + x[i__5].i * temp.r;
            z__1.r = a[i__4].r + z__2.r , z__1.i = a[i__4].i + z__2.i;
            a[i__3].r = z__1.r , a[i__3].i = z__1.i;
        }
    }
    jy += *incy;
}
}
