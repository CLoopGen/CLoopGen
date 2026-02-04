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
extern integer jy;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = jy;
    singlecomplex y_val = y[i__2];
    int non_zero = (y_val.r != 0.F || y_val.i != 0.F);
    if (non_zero) {
        q__1.r = alpha->r * y_val.r - alpha->i * y_val.i;
        q__1.i = alpha->r * y_val.i + alpha->i * y_val.r;
        temp.r = q__1.r; temp.i = q__1.i;
        for (i__ = 1; i__ <= *m; ++i__) {
            i__3 = i__ + j * a_dim1;
            q__2.r = x[i__].r * temp.r - x[i__].i * temp.i;
            q__2.i = x[i__].r * temp.i + x[i__].i * temp.r;
            a[i__3].r += q__2.r;
            a[i__3].i += q__2.i;
        }
    }
    jy += *incy;
}
}
