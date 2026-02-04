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

typedef int logical;

extern integer *n;
extern doublecomplex *a;
extern doublecomplex *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
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
if (*n <= 0) return;
for (j = *n; j >= 1; j -= 2) {
    integer jx1 = jx;
    integer jx2 = jx - *incx;
    integer update1 = 0, update2 = 0;
    if (j >= 1 && (x[jx1].r != 0. || x[jx1].i != 0.)) update1 = 1;
    if (j > 1 && (x[jx2].r != 0. || x[jx2].i != 0.)) update2 = 1;

    if (update1) {
        temp.r = x[jx1].r; temp.i = x[jx1].i;
        ix = kx;
        for (i__ = *n; i__ >= j + 1; --i__) {
            i__2 = ix;
            i__4 = i__ + j * a_dim1;
            z__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
            z__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            x[ix].r += z__2.r;
            x[ix].i += z__2.i;
            ix -= *incx;
        }
        if (nounit) {
            i__3 = j + j * a_dim1;
            z__1.r = x[jx1].r * a[i__3].r - x[jx1].i * a[i__3].i;
            z__1.i = x[jx1].r * a[i__3].i + x[jx1].i * a[i__3].r;
            x[jx1].r = z__1.r;
            x[jx1].i = z__1.i;
        }
    }

    if (update2) {
        temp.r = x[jx2].r; temp.i = x[jx2].i;
        ix = kx - *incx;
        for (i__ = *n; i__ >= j; --i__) {
            i__2 = ix;
            i__4 = i__ + (j-1) * a_dim1;
            z__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
            z__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            x[ix].r += z__2.r;
            x[ix].i += z__2.i;
            ix -= *incx;
        }
        if (nounit) {
            i__3 = (j-1) + (j-1) * a_dim1;
            z__1.r = x[jx2].r * a[i__3].r - x[jx2].i * a[i__3].i;
            z__1.i = x[jx2].r * a[i__3].i + x[jx2].i * a[i__3].r;
            x[jx2].r = z__1.r;
            x[jx2].i = z__1.i;
        }
    }
    jx -= 2 * *incx;
}
}
