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
for (j = 1; j <= i__1; j += 2) {
    i__2 = jx;
    i__3 = jx + *incx;
    if (x[i__2].r != 0.F || x[i__2].i != 0.F || 
        (j + 1 <= i__1 && (x[i__3].r != 0.F || x[i__3].i != 0.F))) {
        iy = ky;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            temp.r = 0.F; temp.i = 0.F;
            if (x[i__2].r != 0.F || x[i__2].i != 0.F) {
                q__1.r = alpha->r * x[i__2].r - alpha->i * x[i__2].i , q__1.i = alpha->r * x[i__2].i + alpha->i * x[i__2].r;
                temp.r += q__1.r; temp.i += q__1.i;
            }
            if (j + 1 <= i__1 && (x[i__3].r != 0.F || x[i__3].i != 0.F)) {
                q__1.r = alpha->r * x[i__3].r - alpha->i * x[i__3].i , q__1.i = alpha->r * x[i__3].i + alpha->i * x[i__3].r;
                q__2.r = q__1.r * a[i__ + (j+1) * a_dim1].r - q__1.i * a[i__ + (j+1) * a_dim1].i;
                q__2.i = q__1.r * a[i__ + (j+1) * a_dim1].i + q__1.i * a[i__ + (j+1) * a_dim1].r;
                temp.r += q__2.r; temp.i += q__2.i;
            }
            i__4 = iy;
            i__5 = iy;
            q__1.r = y[i__4].r + temp.r , q__1.i = y[i__4].i + temp.i;
            y[i__5].r = q__1.r , y[i__5].i = q__1.i;
            iy += *incy;
        }
    }
    jx += *incx * 2;
}
}
