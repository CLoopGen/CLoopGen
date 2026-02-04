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
    if (x[i__2].r != 0.F || x[i__2].i != 0.F) {
        i__2 = jx;
        q__1.r = alpha->r * x[i__2].r - alpha->i * x[i__2].i , q__1.i = alpha->r * x[i__2].i + alpha->i * x[i__2].r;
        temp.r = q__1.r , temp.i = q__1.i;
        iy = ky;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; i__ += 2) {
            i__3 = iy;
            i__4 = iy;
            i__5 = i__ + j * a_dim1;
            q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            q__1.r = y[i__4].r + q__2.r , q__1.i = y[i__4].i + q__2.i;
            y[i__3].r = q__1.r , y[i__3].i = q__1.i;

            if (i__ + 1 <= i__2) {
                i__3 = iy + *incy;
                i__4 = iy + *incy;
                i__5 = i__ + 1 + j * a_dim1;
                q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                q__1.r = y[i__4].r + q__2.r , q__1.i = y[i__4].i + q__2.i;
                y[i__3].r = q__1.r , y[i__3].i = q__1.i;
            }
            iy += *incy * 2;
        }
    }
    jx += *incx;
}
}
