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
// Variant 2: Strided memory access with loop interchange for improved cache reuse
// We reverse the loop order on k and i to increase spatial locality in B
for (j = *n; j >= 1; --j) {
    temp.r = alpha->r; temp.i = alpha->i;
    if (nounit) {
        i__1 = j + j * a_dim1;
        z__1.r = temp.r * a[i__1].r - temp.i * a[i__1].i;
        z__1.i = temp.r * a[i__1].i + temp.i * a[i__1].r;
        temp.r = z__1.r; temp.i = z__1.i;
    }

    // Scale column j of B by temp using strided write pattern
    for (i__ = 1; i__ <= *m; ++i__) {
        i__2 = i__ + j * b_dim1;
        z__1.r = temp.r * b[i__2].r - temp.i * b[i__2].i;
        z__1.i = temp.r * b[i__2].i + temp.i * b[i__2].r;
        b[i__2].r = z__1.r; b[i__2].i = z__1.i;
    }

    // Perform updates from A(k,j) with loop over i moved inside k, but access B(i,k) with stride
    i__1 = j - 1;
    for (k = 1; k <= i__1; ++k) {
        i__2 = k + j * a_dim1;
        if (a[i__2].r != 0. || a[i__2].i != 0.) {
            z__1.r = alpha->r * a[i__2].r - alpha->i * a[i__2].i;
            z__1.i = alpha->r * a[i__2].i + alpha->i * a[i__2].r;
            temp.r = z__1.r; temp.i = z__1.i;

            // Update column j of B using strided read from column k of B
            for (i__ = 1; i__ <= *m; ++i__) {
                i__3 = i__ + j * b_dim1;
                i__5 = i__ + k * b_dim1;
                z__2.r = temp.r * b[i__5].r - temp.i * b[i__5].i;
                z__2.i = temp.r * b[i__5].i + temp.i * b[i__5].r;
                b[i__3].r += z__2.r;
                b[i__3].i += z__2.i;
            }
        }
    }
}
}
