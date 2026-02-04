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

typedef int logical;

extern integer *n;
extern singlecomplex *a;
extern singlecomplex *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
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
for (j = *n; j >= 1; --j) {
    i__1 = jx;
    if (x[i__1].r != 0.F || x[i__1].i != 0.F) {
        i__1 = jx;
        temp.r = x[i__1].r , temp.i = x[i__1].i;
        ix = kx;
        i__1 = j + 1;
        // Introduce temporary accumulation to modify RAW/WAW dependencies
        singlecomplex sum;
        sum.r = 0.0f; sum.i = 0.0f;
        for (i__ = *n; i__ >= i__1; --i__) {
            i__4 = i__ + j * a_dim1;
            q__2.r = temp.r * a[i__4].r - temp.i * a[i__4].i;
            q__2.i = temp.r * a[i__4].i + temp.i * a[i__4].r;
            sum.r += q__2.r;
            sum.i += q__2.i;
            ix -= *incx;
        }
        // Accumulate all contributions first, then update x once (reduces WAW and introduces loop-carried dependency via sum)
        i__2 = jx;
        q__1.r = x[i__2].r + sum.r;
        q__1.i = x[i__2].i + sum.i;
        x[i__2].r = q__1.r;
        x[i__2].i = q__1.i;

        if (nounit) {
            i__1 = jx;
            i__2 = jx;
            i__3 = j + j * a_dim1;
            q__1.r = x[i__2].r * a[i__3].r - x[i__2].i * a[i__3].i;
            q__1.i = x[i__2].r * a[i__3].i + x[i__2].i * a[i__3].r;
            x[i__1].r = q__1.r;
            x[i__1].i = q__1.i;
        }
    }
    jx -= *incx;
}
}
