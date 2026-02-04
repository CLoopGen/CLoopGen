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
for (j = 1; j <= i__1; j += 2) {
    i__2 = jy;
    i__3 = jy + *incy;
    if (y[i__2].r != 0.F || y[i__2].i != 0.F) {
        q__1.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i , q__1.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        temp.r = q__1.r , temp.i = q__1.i;
        ix = kx;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__4 = i__ + j * a_dim1;
            i__5 = ix;
            q__2.r = x[i__5].r * temp.r - x[i__5].i * temp.i , q__2.i = x[i__5].r * temp.i + x[i__5].i * temp.r;
            a[i__4].r += q__2.r , a[i__4].i += q__2.i;
            ix += *incx;
        }
    }
    if (j + 1 <= i__1 && (y[i__3].r != 0.F || y[i__3].i != 0.F)) {
        q__1.r = alpha->r * y[i__3].r - alpha->i * y[i__3].i , q__1.i = alpha->r * y[i__3].i + alpha->i * y[i__3].r;
        temp.r = q__1.r , temp.i = q__1.i;
        ix = kx;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__4 = i__ + (j + 1) * a_dim1;
            i__5 = ix;
            q__2.r = x[i__5].r * temp.r - x[i__5].i * temp.i , q__2.i = x[i__5].r * temp.i + x[i__5].i * temp.r;
            a[i__4].r += q__2.r , a[i__4].i += q__2.i;
            ix += *incx;
        }
    }
    jy += *incy * 2;
}
}
