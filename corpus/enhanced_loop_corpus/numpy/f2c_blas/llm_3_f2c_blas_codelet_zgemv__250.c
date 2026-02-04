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
extern integer *incy;
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
extern integer iy;
extern integer jx;
extern integer ky;
extern doublecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Consecutive memory access pattern by reindexing arrays to access in row-major order
integer ix = 0, offset_a, offset_y;
for (j = 0; j < i__1; ++j) {
    if (x[ix].r != 0. || x[ix].i != 0.) {
        z__1.r = alpha->r * x[ix].r - alpha->i * x[ix].i;
        z__1.i = alpha->r * x[ix].i + alpha->i * x[ix].r;
        temp.r = z__1.r; temp.i = z__1.i;
        integer base_y = 0;
        for (i__ = 0; i__ < *m; ++i__) {
            offset_a = i__ + j * a_dim1;
            offset_y = base_y;
            z__2.r = temp.r * a[offset_a].r - temp.i * a[offset_a].i;
            z__2.i = temp.r * a[offset_a].i + temp.i * a[offset_a].r;
            y[offset_y].r += z__2.r;
            y[offset_y].i += z__2.i;
            base_y += 1; // consecutive write to y
        }
    }
    ix += *incx; // still respects original stride but starts from 0
}
}
