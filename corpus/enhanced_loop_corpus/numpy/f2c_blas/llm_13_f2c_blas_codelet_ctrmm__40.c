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

extern integer *m;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern integer i__6;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer k;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        i__3 = k + j * b_dim1;
        if (b[i__3].r == 0.F && b[i__3].i == 0.F) continue;
        i__3 = k + j * b_dim1;
        q__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i , q__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
        temp.r = q__1.r , temp.i = q__1.i;

        i__3 = k - 1;
        if (i__3 >= 8) {
            for (i__ = 1; i__ <= i__3 - 3; i__ += 4) {
                i__4 = i__   + j * b_dim1;
                i__5 = i__   + j * b_dim1;
                i__6 = i__   + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                q__1.r = b[i__5].r + q__2.r , q__1.i = b[i__5].i + q__2.i;
                b[i__4].r = q__1.r , b[i__4].i = q__1.i;

                i__4 = i__+1 + j * b_dim1;
                i__5 = i__+1 + j * b_dim1;
                i__6 = i__+1 + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                q__1.r = b[i__5].r + q__2.r , q__1.i = b[i__5].i + q__2.i;
                b[i__4].r = q__1.r , b[i__4].i = q__1.i;

                i__4 = i__+2 + j * b_dim1;
                i__5 = i__+2 + j * b_dim1;
                i__6 = i__+2 + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                q__1.r = b[i__5].r + q__2.r , q__1.i = b[i__5].i + q__2.i;
                b[i__4].r = q__1.r , b[i__4].i = q__1.i;

                i__4 = i__+3 + j * b_dim1;
                i__5 = i__+3 + j * b_dim1;
                i__6 = i__+3 + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                q__1.r = b[i__5].r + q__2.r , q__1.i = b[i__5].i + q__2.i;
                b[i__4].r = q__1.r , b[i__4].i = q__1.i;
            }
            for (; i__ <= i__3; ++i__) {
                i__4 = i__ + j * b_dim1;
                i__5 = i__ + j * b_dim1;
                i__6 = i__ + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                q__1.r = b[i__5].r + q__2.r , q__1.i = b[i__5].i + q__2.i;
                b[i__4].r = q__1.r , b[i__4].i = q__1.i;
            }
        } else {
            for (i__ = 1; i__ <= i__3; ++i__) {
                i__4 = i__ + j * b_dim1;
                i__5 = i__ + j * b_dim1;
                i__6 = i__ + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                q__1.r = b[i__5].r + q__2.r , q__1.i = b[i__5].i + q__2.i;
                b[i__4].r = q__1.r , b[i__4].i = q__1.i;
            }
        }

        if (nounit) {
            i__3 = k + k * a_dim1;
            q__1.r = temp.r * a[i__3].r - temp.i * a[i__3].i , q__1.i = temp.r * a[i__3].i + temp.i * a[i__3].r;
            temp.r = q__1.r , temp.i = q__1.i;
        }
        i__3 = k + j * b_dim1;
        b[i__3].r = temp.r , b[i__3].i = temp.i;
    }
}
}
