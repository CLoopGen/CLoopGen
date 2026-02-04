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
integer local_jy = jy;
for (j = 1; j <= i__1; ++j) {
    i__2 = local_jy;
    if (y[i__2].r != 0.F || y[i__2].i != 0.F) {
        singlecomplex scaled_y;
        scaled_y.r = alpha->r * y[i__2].r - alpha->i * y[i__2].i;
        scaled_y.i = alpha->r * y[i__2].i + alpha->i * y[i__2].r;
        integer local_ix = kx;
        for (i__ = 1; i__ <= *m; ++i__) {
            integer a_index = i__ + j * a_dim1;
            integer x_index = local_ix;
            singlecomplex product;
            product.r = x[x_index].r * scaled_y.r - x[x_index].i * scaled_y.i;
            product.i = x[x_index].r * scaled_y.i + x[x_index].i * scaled_y.r;
            a[a_index].r += product.r;
            a[a_index].i += product.i;
            local_ix += *incx;
        }
    }
    local_jy += *incy;
}
jy = local_jy;
}
