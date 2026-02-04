#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int logical;

extern integer *m;
extern integer *n;
extern doublecomplex *alpha;
extern doublecomplex *a;
extern doublecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    doublecomplex scale;
    scale.r = alpha->r;
    scale.i = alpha->i;
    if (nounit) {
        i__1 = j + j * a_dim1;
        z__1.r = scale.r * a[i__1].r - scale.i * a[i__1].i;
        z__1.i = scale.r * a[i__1].i + scale.i * a[i__1].r;
        scale.r = z__1.r;
        scale.i = z__1.i;
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + j * b_dim1;
        z__1.r = scale.r * b[i__2].r - scale.i * b[i__2].i;
        z__1.i = scale.r * b[i__2].i + scale.i * b[i__2].r;
        b[i__2].r = z__1.r;
        b[i__2].i = z__1.i;
    }
    i__1 = j - 1;
    for (k = 1; k <= i__1; ++k) {
        i__2 = k + j * a_dim1;
        if (a[i__2].r != 0. || a[i__2].i != 0.) {
            i__2 = k + j * a_dim1;
            z__1.r = alpha->r * a[i__2].r - alpha->i * a[i__2].i;
            z__1.i = alpha->r * a[i__2].i + alpha->i * a[i__2].r;
            doublecomplex beta_k;
            beta_k.r = z__1.r;
            beta_k.i = z__1.i;
            i__2 = *m;
            for (i__ = 1; i__ <= i__2; ++i__) {
                i__3 = i__ + k * b_dim1;
                i__4 = i__ + j * b_dim1;
                z__2.r = beta_k.r * b[i__3].r - beta_k.i * b[i__3].i;
                z__2.i = beta_k.r * b[i__3].i + beta_k.i * b[i__3].r;
                b[i__4].r += z__2.r;
                b[i__4].i += z__2.i;
            }
        }
    }
}
}
