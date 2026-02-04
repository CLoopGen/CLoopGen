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
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t cj_off = j * c_dim1;
    if (beta->r == 0. && beta->i == 0.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            ptrdiff_t idx = i__ + cj_off;
            c__[idx].r = 0.0;
            c__[idx].i = 0.0;
        }
    } else if (beta->r != 1. || beta->i != 0.) {
        for (i__ = 1; i__ <= *m; ++i__) {
            ptrdiff_t idx = i__ + cj_off;
            doublereal cr = c__[idx].r, ci = c__[idx].i;
            z__1.r = beta->r * cr - beta->i * ci;
            z__1.i = beta->r * ci + beta->i * cr;
            c__[idx].r = z__1.r;
            c__[idx].i = z__1.i;
        }
    }
    for (l = 1; l <= *k; ++l) {
        ptrdiff_t bj_off = l + j * b_dim1;
        if (b[bj_off].r != 0. || b[bj_off].i != 0.) {
            z__1.r = alpha->r * b[bj_off].r - alpha->i * b[bj_off].i;
            z__1.i = alpha->r * b[bj_off].i + alpha->i * b[bj_off].r;
            temp.r = z__1.r; temp.i = z__1.i;
            ptrdiff_t al_off_base = l * a_dim1;
            for (i__ = 1; i__ <= *m; ++i__) {
                ptrdiff_t ci_off = i__ + cj_off;
                ptrdiff_t ai_off = i__ + al_off_base;
                z__2.r = temp.r * a[ai_off].r - temp.i * a[ai_off].i;
                z__2.i = temp.r * a[ai_off].i + temp.i * a[ai_off].r;
                c__[ci_off].r += z__2.r;
                c__[ci_off].i += z__2.i;
            }
        }
    }
}
}
