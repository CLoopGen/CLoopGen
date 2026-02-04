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
    i__2 = jx;
    if (x[i__2].r != 0. || x[i__2].i != 0.) {
        i__2 = jx;
        z__1.r = alpha->r * x[i__2].r - alpha->i * x[i__2].i , z__1.i = alpha->r * x[i__2].i + alpha->i * x[i__2].r;
        temp.r = z__1.r , temp.i = z__1.i;
        i__2 = *m;
        for (i__ = i__2; i__ >= 1; --i__) {
            i__3 = i__;
            i__4 = i__;
            i__5 = i__ + j * a_dim1;
            z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            z__1.r = y[i__4].r + z__2.r , z__1.i = y[i__4].i + z__2.i;
            y[i__3].r = z__1.r , y[i__3].i = z__1.i;
        }
    }
    jx += *incx;
}
}
