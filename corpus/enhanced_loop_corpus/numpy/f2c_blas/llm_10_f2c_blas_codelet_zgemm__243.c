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
extern integer i__6;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer l;
extern doublecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reverse loop order to change data access pattern and modify loop-carried dependency flow
for (j = i__1; j >= 1; --j) {
    // First, scale c[:,j] by beta using direct assignment with reversed index
    if (beta->r != 1. || beta->i != 0.) {
        for (i__ = *m; i__ >= 1; --i__) {
            i__3 = i__ + j * c_dim1;
            z__1.r = beta->r * c__[i__3].r - beta->i * c__[i__3].i;
            z__1.i = beta->r * c__[i__3].i + beta->i * c__[i__3].r;
            c__[i__3].r = z__1.r;
            c__[i__3].i = z__1.i;
        }
    } else if (beta->r == 0. && beta->i == 0.) {
        for (i__ = *m; i__ >= 1; --i__) {
            i__3 = i__ + j * c_dim1;
            c__[i__3].r = 0.;
            c__[i__3].i = 0.;
        }
    }

    // Process B and A contributions in reverse l order to alter accumulation order (associative but changes floating-point behavior slightly)
    for (l = *k; l >= 1; --l) {
        i__3 = j + l * b_dim1;
        if (b[i__3].r != 0. || b[i__3].i != 0.) {
            z__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i;
            z__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            temp.r = z__1.r;
            temp.i = z__1.i;

            for (i__ = *m; i__ >= 1; --i__) {
                i__4 = i__ + j * c_dim1;
                i__5 = i__ + j * c_dim1;
                i__6 = i__ + l * a_dim1;
                z__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i;
                z__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                z__1.r = c__[i__5].r + z__2.r;
                z__1.i = c__[i__5].i + z__2.i;
                c__[i__4].r = z__1.r;
                c__[i__4].i = z__1.i;
            }
        }
    }
}
}
