#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

typedef int logical;

extern doublecomplex *a;
extern doublecomplex *x;
extern integer *incx;
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
extern integer ix;
extern integer jx;
extern integer kx;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = jx;
    if (x[i__2].r == 0. && x[i__2].i == 0.) {
        jx += *incx;
        continue;
    }
    temp.r = x[i__2].r , temp.i = x[i__2].i;
    ix = kx;
    i__2 = j - 1;
    if (i__2 >= 1) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = ix;
            i__4 = ix;
            i__5 = i__ + j * a_dim1;
            z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            z__1.r = x[i__4].r + z__2.r , z__1.i = x[i__4].i + z__2.i;
            x[i__3].r = z__1.r , x[i__3].i = z__1.i;
            ix += *incx;
        }
    }
    if (nounit) {
        i__2 = jx;
        i__3 = jx;
        i__4 = j + j * a_dim1;
        z__1.r = x[i__3].r * a[i__4].r - x[i__3].i * a[i__4].i , z__1.i = x[i__3].r * a[i__4].i + x[i__3].i * a[i__4].r;
        x[i__2].r = z__1.r , x[i__2].i = z__1.i;
    }
    jx += *incx;
}
}
