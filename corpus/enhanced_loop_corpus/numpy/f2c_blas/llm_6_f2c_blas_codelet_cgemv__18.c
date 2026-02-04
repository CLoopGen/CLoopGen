#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *x;
extern integer *incx;
extern singlecomplex *y;
extern integer *incy;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer iy;
extern integer jx;
extern integer ky;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = jx;
    i__3 = jx;
    int skip_computation = (x[i__2].r == 0.F && x[i__3].i == 0.F);
    if (!skip_computation) {
        q__1.r = alpha->r * x[jx].r - alpha->i * x[jx].i;
        q__1.i = alpha->r * x[jx].i + alpha->i * x[jx].r;
        temp.r = q__1.r;
        temp.i = q__1.i;
        iy = ky;
        for (i__ = 1; i__ <= *m; ++i__) {
            i__3 = iy;
            i__4 = iy;
            i__5 = i__ + j * a_dim1;
            q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
            q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            y[i__3].r += q__2.r;
            y[i__3].i += q__2.i;
            iy += *incy;
        }
    }
    jx += *incx;
}
}
