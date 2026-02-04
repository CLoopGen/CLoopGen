#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

typedef int logical;

extern singlecomplex *a;
extern singlecomplex *x;
extern integer *incx;
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
extern integer jx;
extern integer kx;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = jx;
    if (x[i__2].r != 0.F || x[i__2].i != 0.F) {
        i__2 = jx;
        temp.r = x[i__2].r , temp.i = x[i__2].i;
        ix = kx;
        i__2 = j - 1;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = ix;
            i__4 = ix;
            i__5 = i__ + j * a_dim1;
            // Introduce temporary accumulation to modify RAW/WAW dependencies
            real tr = temp.r * a[i__5].r - temp.i * a[i__5].i;
            real ti = temp.r * a[i__5].i + temp.i * a[i__5].r;
            real xr = x[i__4].r + tr;
            real xi = x[i__4].i + ti;
            // Delay write to break potential WAW hazard with prior iterations
            x[i__3].r = xr;
            x[i__3].i = xi;
            ix += *incx;
        }
        if (nounit) {
            i__2 = jx;
            i__3 = jx;
            i__4 = j + j * a_dim1;
            // Break dependency chain by using intermediate variables
            real ar = a[i__4].r, ai = a[i__4].i;
            real xr = x[i__3].r, xi = x[i__3].i;
            q__1.r = xr * ar - xi * ai;
            q__1.i = xr * ai + xi * ar;
            x[i__2].r = q__1.r;
            x[i__2].i = q__1.i;
        }
    }
    jx += *incx;
}
}
