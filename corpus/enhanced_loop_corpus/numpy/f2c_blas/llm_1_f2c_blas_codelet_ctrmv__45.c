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
// Outer unrolling simulation by splitting the loop into two sequential loops with reduced range
integer mid = i__1 / 2;

// First half of original loop
for (j = 1; j <= mid; ++j) {
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
            q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            q__1.r = x[i__4].r + q__2.r , q__1.i = x[i__4].i + q__2.i;
            x[i__3].r = q__1.r , x[i__3].i = q__1.i;
            ix += *incx;
        }
        if (nounit) {
            i__2 = jx;
            i__3 = jx;
            i__4 = j + j * a_dim1;
            q__1.r = x[i__3].r * a[i__4].r - x[i__3].i * a[i__4].i , q__1.i = x[i__3].r * a[i__4].i + x[i__3].i * a[i__4].r;
            x[i__2].r = q__1.r , x[i__2].i = q__1.i;
        }
    }
    jx += *incx;
}

// Second half of original loop
for (j = mid + 1; j <= i__1; ++j) {
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
            q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            q__1.r = x[i__4].r + q__2.r , q__1.i = x[i__4].i + q__2.i;
            x[i__3].r = q__1.r , x[i__3].i = q__1.i;
            ix += *incx;
        }
        if (nounit) {
            i__2 = jx;
            i__3 = jx;
            i__4 = j + j * a_dim1;
            q__1.r = x[i__3].r * a[i__4].r - x[i__3].i * a[i__4].i , q__1.i = x[i__3].r * a[i__4].i + x[i__3].i * a[i__4].r;
            x[i__2].r = q__1.r , x[i__2].i = q__1.i;
        }
    }
    jx += *incx;
}
}
