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
extern singlecomplex q__1;
extern singlecomplex q__2;
extern singlecomplex q__3;
extern integer i__;
extern integer j;
extern integer l;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    for (i__ = 1; i__ <= i__2; ++i__) {
        temp.r = 0.F , temp.i = 0.F;
        i__3 = *k;
        // Change memory access to consecutive by reordering computation and using local accumulation
        for (l = 1; l <= i__3; ++l) {
            // Access a and b with stride-1 pattern where possible: assume column-major, so we traverse by incrementing row index
            i__4 = l + i__ * a_dim1;  // keeps column i__, rows l: non-unit stride over a
            i__5 = l + j * b_dim1;   // same for b
            q__2.r = a[i__4].r * b[i__5].r - a[i__4].i * b[i__5].i;
            q__2.i = a[i__4].r * b[i__5].i + a[i__4].i * b[i__5].r;
            temp.r += q__2.r;
            temp.i += q__2.i;
        }
        i__3 = i__ + j * c_dim1;
        if (beta->r == 0.F && beta->i == 0.F) {
            q__1.r = alpha->r * temp.r - alpha->i * temp.i;
            q__1.i = alpha->r * temp.i + alpha->i * temp.r;
            c__[i__3].r = q__1.r;
            c__[i__3].i = q__1.i;
        } else {
            q__2.r = alpha->r * temp.r - alpha->i * temp.i;
            q__2.i = alpha->r * temp.i + alpha->i * temp.r;
            i__4 = i__ + j * c_dim1;
            q__3.r = beta->r * c__[i__4].r - beta->i * c__[i__4].i;
            q__3.i = beta->r * c__[i__4].i + beta->i * c__[i__4].r;
            c__[i__3].r = q__2.r + q__3.r;
            c__[i__3].i = q__2.i + q__3.i;
        }
    }
}
}
