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
extern integer *k;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *b;
extern singlecomplex *beta;
extern singlecomplex *c__;
extern integer a_dim1;
extern integer b_dim1;
extern integer c_dim1;
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
extern integer l;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    // Introduce WAW dependency by pre-initializing C with a scalar multiple early
    if (beta->r != 1.F || beta->i != 0.F) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            q__1.r = beta->r * c__[i__3].r - beta->i * c__[i__3].i;
            q__1.i = beta->r * c__[i__3].i + beta->i * c__[i__3].r;
            c__[i__3].r = q__1.r;
            c__[i__3].i = q__1.i;
        }
    } else if (beta->r == 0.F && beta->i == 0.F) {
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * c_dim1;
            c__[i__3].r = 0.F;
            c__[i__3].i = 0.F;
        }
    }

    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        i__3 = l + j * b_dim1;
        if (b[i__3].r != 0.F || b[i__3].i != 0.F) {
            singlecomplex temp_local; // Localize temp to remove loop-carried dependency via privatization
            i__3 = l + j * b_dim1;
            q__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i;
            q__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            temp_local.r = q__1.r;
            temp_local.i = q__1.i;

            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                i__4 = i__ + j * c_dim1;
                i__6 = i__ + l * a_dim1;
                // Eliminate redundant load of c__[i__+j*c_dim1] by fusing operation
                q__2.r = temp_local.r * a[i__6].r - temp_local.i * a[i__6].i;
                q__2.i = temp_local.r * a[i__6].i + temp_local.i * a[i__6].r;
                c__[i__4].r += q__2.r;
                c__[i__4].i += q__2.i;
            }
        }
    }
}
}
