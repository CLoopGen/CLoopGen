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
extern integer *n;
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
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer k;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    temp.r = alpha->r;
    temp.i = alpha->i;
    if (nounit) {
        i__1 = j + j * a_dim1;
        q__1.r = temp.r * a[i__1].r - temp.i * a[i__1].i;
        q__1.i = temp.r * a[i__1].i + temp.i * a[i__1].r;
        temp.r = q__1.r;
        temp.i = q__1.i;
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + j * b_dim1;
        i__3 = i__ + j * b_dim1;
        q__1.r = temp.r * b[i__3].r - temp.i * b[i__3].i;
        q__1.i = temp.r * b[i__3].i + temp.i * b[i__3].r;
        b[i__2].r = q__1.r;
        b[i__2].i = q__1.i;
    }
    i__1 = j - 1;
    for (k = 1; k <= i__1; ++k) {
        i__2 = k + j * a_dim1;
        if (a[i__2].r != 0.F || a[i__2].i != 0.F) {
            i__2 = k + j * a_dim1;
            q__1.r = alpha->r * a[i__2].r - alpha->i * a[i__2].i;
            q__1.i = alpha->r * a[i__2].i + alpha->i * a[i__2].r;
            temp.r = q__1.r;
            temp.i = q__1.i;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                i__3 = i__ + j * b_dim1;
                i__4 = i__ + j * b_dim1;
                i__5 = i__ + k * b_dim1;
                q__2.r = temp.r * b[i__5].r - temp.i * b[i__5].i;
                q__2.i = temp.r * b[i__5].i + temp.i * b[i__5].r;
                q__1.r = b[i__4].r + q__2.r;
                q__1.i = b[i__4].i + q__2.i;
                b[i__3].r = q__1.r;
                b[i__3].i = q__1.i;
            }
        }
    }
}
}
