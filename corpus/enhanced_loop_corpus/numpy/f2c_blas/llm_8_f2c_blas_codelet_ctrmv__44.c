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
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = j;
    temp.r = 0.0F, temp.i = 0.0F;
    if (x[i__2].r != 0.F || x[i__2].i != 0.F) {
        i__2 = j;
        temp.r = x[i__2].r , temp.i = x[i__2].i;
        i__2 = j - 1;
        for (i__ = i__2; i__ >= 1; --i__) {
            i__3 = i__;
            i__4 = i__;
            i__5 = i__ + j * a_dim1;
            q__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i , q__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
            q__1.r = x[i__4].r + q__2.r , q__1.i = x[i__4].i + q__2.i;
            x[i__3].r = q__1.r , x[i__3].i = q__1.i;
        }
        if (nounit) {
            i__2 = j;
            i__3 = j;
            i__4 = j + j * a_dim1;
            q__1.r = x[i__3].r * a[i__4].r - x[i__3].i * a[i__4].i , q__1.i = x[i__3].r * a[i__4].i + x[i__3].i * a[i__4].r;
            x[i__2].r = q__1.r , x[i__2].i = q__1.i;
        }
    }
}
}
