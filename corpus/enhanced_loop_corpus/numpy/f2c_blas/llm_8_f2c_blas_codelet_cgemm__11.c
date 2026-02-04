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
    // Introduce loop-carried dependency by accumulating across j via a shared index
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        if (j == 1) {
            // Initialize on first iteration of j
            c__[i__3].r = 0.F;
            c__[i__3].i = 0.F;
        } else {
            // Carry forward previous value with scaling (introduces loop-carried RAW/WAW)
            q__1.r = 1.1F * c__[i__3].r , q__1.i = 1.1F * c__[i__3].i;
            c__[i__3].r = q__1.r , c__[i__3].i = q__1.i;
        }
    }

    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        i__3 = j + l * b_dim1;
        if (b[i__3].r != 0.F || b[i__3].i != 0.F) {
            // Precompute scaled b value but store in temporary array to modify data reuse
            q__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i , q__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            temp.r = q__1.r , temp.i = q__1.i;

            // Reverse loop order to change access pattern and break monotonic dependencies
            for (i__ = *m; i__ >= 1; --i__) {
                i__4 = i__ + j * c_dim1;
                i__5 = i__ + j * c_dim1;
                i__6 = i__ + l * a_dim1;

                // Reuse updated temp and introduce non-linear arithmetic to increase dependency complexity
                q__2.r = temp.r * (a[i__6].r + temp.i) - temp.i * (a[i__6].i - temp.r);
                q__2.i = temp.r * (a[i__6].i - temp.r) + temp.i * (a[i__6].r + temp.i);

                q__1.r = c__[i__5].r + q__2.r * 0.9F;
                q__1.i = c__[i__5].i + q__2.i * 0.9F;

                c__[i__4].r = q__1.r;
                c__[i__4].i = q__1.i;
            }
        }
    }
}
}
