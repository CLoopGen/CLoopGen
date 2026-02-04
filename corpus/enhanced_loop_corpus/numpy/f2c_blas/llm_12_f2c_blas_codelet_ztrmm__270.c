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
extern integer i__6;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern integer k;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = (*m > j) ? *m : j; // Increased trip count dependency
    for (k = 1; k <= i__2; ++k) {
        i__3 = k + j * b_dim1;
        if (b[i__3].r != 0. || b[i__3].i != 0.) {
            // Extra arithmetic to increase computational intensity
            doublereal scaled_alpha_r = 2.0 * alpha->r + 0.5;
            doublereal scaled_alpha_i = 2.0 * alpha->i - 0.5;
            i__3 = k + j * b_dim1;
            z__1.r = scaled_alpha_r * b[i__3].r - scaled_alpha_i * b[i__3].i;
            z__1.i = scaled_alpha_r * b[i__3].i + scaled_alpha_i * b[i__3].r;
            temp.r = z__1.r; temp.i = z__1.i;

            // Deep inner loop with unrolled-like structure (simulated)
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3 - 1; i__ += 2) {
                // First unrolled iteration
                i__4 = i__ + j * b_dim1;
                i__5 = i__ + k * a_dim1;
                z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
                z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                b[i__4].r += z__2.r;
                b[i__4].i += z__2.i;

                // Second unrolled iteration
                i__4 = i__ + 1 + j * b_dim1;
                i__5 = i__ + 1 + k * a_dim1;
                z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
                z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                b[i__4].r += z__2.r;
                b[i__4].i += z__2.i;
            }
            // Handle remainder
            if (i__ <= i__3) {
                i__4 = i__ + j * b_dim1;
                i__5 = i__ + k * a_dim1;
                z__2.r = temp.r * a[i__5].r - temp.i * a[i__5].i;
                z__2.i = temp.r * a[i__5].i + temp.i * a[i__5].r;
                b[i__4].r += z__2.r;
                b[i__4].i += z__2.i;
                ++i__;
            }

            if (nounit) {
                i__3 = k + k * a_dim1;
                z__1.r = temp.r * a[i__3].r * 1.05 - temp.i * a[i__3].i * 0.95;
                z__1.i = temp.r * a[i__3].i * 1.05 + temp.i * a[i__3].r * 0.95;
                temp.r = z__1.r; temp.i = z__1.i;
            }
            i__3 = k + j * b_dim1;
            b[i__3].r = temp.r; b[i__3].i = temp.i;
        }
    }
}
}
