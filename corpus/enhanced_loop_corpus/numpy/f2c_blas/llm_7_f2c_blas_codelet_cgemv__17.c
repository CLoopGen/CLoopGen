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
extern integer jx;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
real temp_r, temp_i;
for (j = 1; j <= i__1; ++j) {
    i__2 = jx;
    if (x[i__2].r != 0.F || x[i__2].i != 0.F) {
        i__2 = jx;
        temp_r = alpha->r * x[i__2].r - alpha->i * x[i__2].i;
        temp_i = alpha->r * x[i__2].i + alpha->i * x[i__2].r;
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__;
            i__5 = i__ + j * a_dim1;
            real tr = temp_r * a[i__5].r - temp_i * a[i__5].i;
            real ti = temp_r * a[i__5].i + temp_i * a[i__5].r;
            y[i__3].r += tr;
            y[i__3].i += ti;
        }
    }
    jx += *incx;
}
}
