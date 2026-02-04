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
extern singlecomplex *x;
extern integer *incx;
extern singlecomplex *y;
extern integer *incy;
extern singlecomplex *a;
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
extern integer ix;
extern integer jy;
extern integer kx;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    if (y[i__2].r == 0.F && y[i__2].i == 0.F) {
        jy += *incy;
        continue;
    }
    i__2 = jy;
    q__1.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i , q__1.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
    temp.r = q__1.r , temp.i = q__1.i;
    ix = kx;
    for (i__ = 1; i__ <= *m; ++i__) {
        i__3 = i__ + j * a_dim1;
        a[i__3].r += x[ix].r * temp.r - x[ix].i * temp.i;
        a[i__3].i += x[ix].r * temp.i + x[ix].i * temp.r;
        ix += *incx;
    }
    jy += *incy;
}
}
