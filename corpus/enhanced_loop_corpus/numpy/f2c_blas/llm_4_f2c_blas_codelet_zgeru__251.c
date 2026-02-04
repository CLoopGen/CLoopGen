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
// Variant with strided memory access pattern: process every other row, forward and backward alternation
integer aj_base, ix;
for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    if (y[i__2].r != 0. || y[i__2].i != 0.) {
        i__2 = jy;
        z__1.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i , z__1.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        temp.r = z__1.r , temp.i = z__1.i;
        aj_base = j * a_dim1;
        // Strided access: step by 2 through rows, alternate direction per column
        if (j % 2 == 1) {
            for (i__ = 1; i__ <= *m; i__ += 2) {
                ix = i__;
                i__3 = ix + aj_base;
                i__4 = i__3;
                z__2.r = x[ix].r * temp.r - x[ix].i * temp.i;
                z__2.i = x[ix].r * temp.i + x[ix].i * temp.r;
                z__1.r = a[i__4].r + z__2.r;
                z__1.i = a[i__4].i + z__2.i;
                a[i__3].r = z__1.r;
                a[i__3].i = z__1.i;
            }
        } else {
            for (i__ = *m; i__ >= 1; i__ -= 2) {
                ix = i__;
                i__3 = ix + aj_base;
                i__4 = i__3;
                z__2.r = x[ix].r * temp.r - x[ix].i * temp.i;
                z__2.i = x[ix].r * temp.i + x[ix].i * temp.r;
                z__1.r = a[i__4].r + z__2.r;
                z__1.i = a[i__4].i + z__2.i;
                a[i__3].r = z__1.r;
                a[i__3].i = z__1.i;
            }
        }
    }
    jy += *incy;
}
}
