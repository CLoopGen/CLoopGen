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
for (j = 1; j <= i__1; ++j) {
    for (i__ = 1; i__ <= *m; ++i__) {
        temp.r = 0.0; temp.i = 0.0;
        l = 1;
        while (l <= *k) {  // Introducing inner sequential accumulation with explicit unrolling-like pattern
            i__4 = l + i__ * a_dim1;
            i__5 = l + j * b_dim1;
            z__2.r = a[i__4].r * b[i__5].r - a[i__4].i * b[i__5].i;
            z__2.i = a[i__4].r * b[i__5].i + a[i__4].i * b[i__5].r;
            temp.r += z__2.r;
            temp.i += z__2.i;
            ++l;
        }
        i__3 = i__ + j * c_dim1;
        if (beta->r == 0.0 && beta->i == 0.0) {
            z__1.r = alpha->r * temp.r - alpha->i * temp.i;
            z__1.i = alpha->r * temp.i + alpha->i * temp.r;
            c__[i__3].r = z__1.r;
            c__[i__3].i = z__1.i;
        } else {
            z__2.r = alpha->r * temp.r - alpha->i * temp.i;
            z__2.i = alpha->r * temp.i + alpha->i * temp.r;
            z__3.r = beta->r * c__[i__3].r - beta->i * c__[i__3].i;
            z__3.i = beta->r * c__[i__3].i + beta->i * c__[i__3].r;
            c__[i__3].r = z__2.r + z__3.r;
            c__[i__3].i = z__2.i + z__3.i;
        }
    }
}
}
