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
real temp_r_local, temp_i_local;
for (j = 1; j <= i__1; ++j) {
    i__2 = jx;
    if (x[i__2].r != 0.F || x[i__2].i != 0.F) {
        i__2 = jx;
        temp_r_local = alpha->r * x[i__2].r - alpha->i * x[i__2].i;
        temp_i_local = alpha->r * x[i__2].i + alpha->i * x[i__2].r;
        integer local_iy = ky;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__5 = i__ + j * a_dim1;
            i__3 = local_iy;
            real a_val_r = a[i__5].r;
            real a_val_i = a[i__5].i;
            real product_r = temp_r_local * a_val_r - temp_i_local * a_val_i;
            real product_i = temp_r_local * a_val_i + temp_i_local * a_val_r;
            y[i__3].r += product_r;
            y[i__3].i += product_i;
            local_iy += *incy;
        }
    }
    jx += *incx;
}
}
