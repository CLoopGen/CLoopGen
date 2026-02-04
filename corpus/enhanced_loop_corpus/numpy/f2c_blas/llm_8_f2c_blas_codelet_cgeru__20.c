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
real temp_r, temp_i;
singlecomplex sum;
for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    if (y[i__2].r != 0.F || y[i__2].i != 0.F) {
        i__2 = jy;
        temp_r = alpha->r * y[i__2].r - alpha->i * y[i__2].i;
        temp_i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        ix = kx;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            i__5 = ix;
            sum.r = a[i__3].r + (x[i__5].r * temp_r - x[i__5].i * temp_i);
            sum.i = a[i__3].i + (x[i__5].r * temp_i + x[i__5].i * temp_r);
            a[i__3].r = sum.r;
            a[i__3].i = sum.i;
            ix += *incx;
        }
    }
    jy += *incy;
}
}
