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
for (j = i__1; j >= 1; --j) {
    integer offset = jy;
    if (y[offset].r != 0. || y[offset].i != 0.) {
        z__1.r = alpha->r * y[offset].r - alpha->i * y[offset].i;
        z__1.i = alpha->r * y[offset].i + alpha->i * y[offset].r;
        temp.r = z__1.r;
        temp.i = z__1.i;
        for (i__ = *m; i__ >= 1; --i__) {
            i__3 = i__ + j * a_dim1;
            i__5 = i__;
            z__2.r = x[i__5].r * temp.r - x[i__5].i * temp.i;
            z__2.i = x[i__5].r * temp.i + x[i__5].i * temp.r;
            a[i__3].r = a[i__3].r + z__2.r;
            a[i__3].i = a[i__3].i + z__2.i;
        }
    }
    jy -= *incy;
}
}
