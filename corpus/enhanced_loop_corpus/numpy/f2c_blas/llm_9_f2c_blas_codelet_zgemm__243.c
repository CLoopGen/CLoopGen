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
    i__2 = *m;
    // Introduce temporary array to eliminate WAW and WAR dependencies via privatization
    doublecomplex *temp_c = (doublecomplex*)alloca(i__2 * sizeof(doublecomplex));
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        if (beta->r == 0. && beta->i == 0.) {
            temp_c[i__-1].r = 0. , temp_c[i__-1].i = 0.;
        } else {
            z__1.r = beta->r * c__[i__3].r - beta->i * c__[i__3].i , z__1.i = beta->r * c__[i__3].i + beta->i * c__[i__3].r;
            temp_c[i__-1].r = z__1.r , temp_c[i__-1].i = z__1.i;
        }
    }
    i__2 = *k;
    for (l = 1; l <= i__2; ++l) {
        i__3 = j + l * b_dim1;
        if (b[i__3].r != 0. || b[i__3].i != 0.) {
            i__3 = j + l * b_dim1;
            z__1.r = alpha->r * b[i__3].r - alpha->i * b[i__3].i , z__1.i = alpha->r * b[i__3].i + alpha->i * b[i__3].r;
            temp.r = z__1.r , temp.i = z__1.i;
            i__3 = *m;
            for (i__ = 1; i__ <= i__3; ++i__) {
                i__6 = i__ + l * a_dim1;
                z__2.r = temp.r * a[i__6].r - temp.i * a[i__6].i , z__2.i = temp.r * a[i__6].i + temp.i * a[i__6].r;
                temp_c[i__-1].r += z__2.r;
                temp_c[i__-1].i += z__2.i;
            }
        }
    }
    // Write back to c__ without interference: eliminates loop-carried WAW/RAW dependencies
    for (i__ = 1; i__ <= *m; ++i__) {
        i__3 = i__ + j * c_dim1;
        c__[i__3].r = temp_c[i__-1].r;
        c__[i__3].i = temp_c[i__-1].i;
    }
}
}
