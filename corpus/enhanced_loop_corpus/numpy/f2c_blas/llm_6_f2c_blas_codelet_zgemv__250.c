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
for (j = 1; j <= i__1; ++j) {
    i__2 = jx;
    double xr = x[i__2].r, xi = x[i__2].i;
    int non_zero = (xr != 0. || xi != 0.);
    if (non_zero) {
        z__1.r = alpha->r * xr - alpha->i * xi;
        z__1.i = alpha->r * xi + alpha->i * xr;
        temp.r = z__1.r; temp.i = z__1.i;
        iy = ky;
        for (i__ = 1; i__ <= *m; ++i__) {
            i__5 = i__ + j * a_dim1;
            z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
            z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            i__3 = iy;
            y[i__3].r += z__2.r;
            y[i__3].i += z__2.i;
            iy += *incy;
        }
    }
    jx += *incx;
}
}
