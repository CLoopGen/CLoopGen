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

extern integer *m;
extern integer *k;
extern doublecomplex *alpha;
extern doublecomplex *a;
extern doublecomplex *b;
extern doublecomplex *beta;
extern doublecomplex *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern doublecomplex z__3;
extern integer i__;
extern integer j;
extern integer l;
extern doublecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; j += 2) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        doublecomplex temp1, temp2;
        temp1.r = 0.; temp1.i = 0.;
        temp2.r = 0.; temp2.i = 0.;
        i__3 = *k;
        for (l = 1; l <= i__3; ++l) {
            i__4 = l + i__ * a_dim1;
            i__5 = l + j * b_dim1;
            z__2.r = a[i__4].r * b[i__5].r - a[i__4].i * b[i__5].i , z__2.i = a[i__4].r * b[i__5].i + a[i__4].i * b[i__5].r;
            z__1.r = temp1.r + z__2.r , z__1.i = temp1.i + z__2.i;
            temp1.r = z__1.r , temp1.i = z__1.i;

            if (j + 1 <= i__1) {
                i__5 = l + (j+1) * b_dim1;
                z__2.r = a[i__4].r * b[i__5].r - a[i__4].i * b[i__5].i , z__2.i = a[i__4].r * b[i__5].i + a[i__4].i * b[i__5].r;
                z__1.r = temp2.r + z__2.r , z__1.i = temp2.i + z__2.i;
                temp2.r = z__1.r , temp2.i = z__1.i;
            }
        }
        if (beta->r == 0. && beta->i == 0.) {
            i__3 = i__ + j * c_dim1;
            z__1.r = alpha->r * temp1.r - alpha->i * temp1.i , z__1.i = alpha->r * temp1.i + alpha->i * temp1.r;
            c__[i__3].r = z__1.r , c__[i__3].i = z__1.i;

            if (j + 1 <= i__1) {
                i__3 = i__ + (j+1) * c_dim1;
                z__1.r = alpha->r * temp2.r - alpha->i * temp2.i , z__1.i = alpha->r * temp2.i + alpha->i * temp2.r;
                c__[i__3].r = z__1.r , c__[i__3].i = z__1.i;
            }
        } else {
            i__3 = i__ + j * c_dim1;
            z__2.r = alpha->r * temp1.r - alpha->i * temp1.i , z__2.i = alpha->r * temp1.i + alpha->i * temp1.r;
            i__4 = i__ + j * c_dim1;
            z__3.r = beta->r * c__[i__4].r - beta->i * c__[i__4].i , z__3.i = beta->r * c__[i__4].i + beta->i * c__[i__4].r;
            z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
            c__[i__3].r = z__1.r , c__[i__3].i = z__1.i;

            if (j + 1 <= i__1) {
                i__3 = i__ + (j+1) * c_dim1;
                z__2.r = alpha->r * temp2.r - alpha->i * temp2.i , z__2.i = alpha->r * temp2.i + alpha->i * temp2.r;
                i__4 = i__ + (j+1) * c_dim1;
                z__3.r = beta->r * c__[i__4].r - beta->i * c__[i__4].i , z__3.i = beta->r * c__[i__4].i + beta->i * c__[i__4].r;
                z__1.r = z__2.r + z__3.r , z__1.i = z__2.i + z__3.i;
                c__[i__3].r = z__1.r , c__[i__3].i = z__1.i;
            }
        }
    }
}
}
