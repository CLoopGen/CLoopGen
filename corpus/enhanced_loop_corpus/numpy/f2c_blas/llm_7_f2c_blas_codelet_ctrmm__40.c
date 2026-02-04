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
        i__4 = k + j * b_dim1;
        q__1.r = alpha->r * b[i__4].r - alpha->i * b[i__4].i , q__1.i = alpha->r * b[i__4].i + alpha->i * b[i__4].r;
        temp.r = q__1.r , temp.i = q__1.i;

        if (b[i__3].r != 0.F || b[i__3].i != 0.F) {
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                i__5 = i__ + j * b_dim1;
                i__6 = i__ + k * a_dim1;
                q__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , q__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                b[i__5].r += q__2.r;
                b[i__5].i += q__2.i;
            }
            if (nounit) {
                i__3 = k + k * a_dim1;
                q__1.r = temp.r * a[i__3].r - temp.i * a[i__3].i , q__1.i = temp.r * a[i__3].i + temp.i * a[i__3].r;
                temp.r = q__1.r , temp.i = q__1.i;
            }
            b[k + j * b_dim1].r = temp.r;
            b[k + j * b_dim1].i = temp.i;
        } else {
            b[k + j * b_dim1].r = 0.0f;
            b[k + j * b_dim1].i = 0.0f;
        }
    }
}
}
