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
    i__2 = *m;
    for (k = 1; k <= i__2; ++k) {
        ptrdiff_t idx_b_kj = (ptrdiff_t)(k + j * b_dim1) - 1; // Convert to zero-based index and use ptrdiff_t
        if (b[idx_b_kj].r != 0. || b[idx_b_kj].i != 0.) {
            z__1.r = alpha->r * b[idx_b_kj].r - alpha->i * b[idx_b_kj].i;
            z__1.i = alpha->r * b[idx_b_kj].i + alpha->i * b[idx_b_kj].r;
            temp.r = z__1.r; temp.i = z__1.i;
            i__3 = k - 1;
            for (i__ = 1; i__ <= i__3; ++i__) {
                ptrdiff_t idx_b_ij = (ptrdiff_t)(i__ + j * b_dim1) - 1;
                ptrdiff_t idx_a_ik = (ptrdiff_t)(i__ + k * a_dim1) - 1;
                z__2.r = temp.r * a[idx_a_ik].r - temp.i * a[idx_a_ik].i;
                z__2.i = temp.r * a[idx_a_ik].i + temp.i * a[idx_a_ik].r;
                z__1.r = b[idx_b_ij].r + z__2.r;
                z__1.i = b[idx_b_ij].i + z__2.i;
                b[idx_b_ij].r = z__1.r;
                b[idx_b_ij].i = z__1.i;
            }
            if (nounit) {
                ptrdiff_t idx_a_kk = (ptrdiff_t)(k + k * a_dim1) - 1;
                z__1.r = temp.r * a[idx_a_kk].r - temp.i * a[idx_a_kk].i;
                z__1.i = temp.r * a[idx_a_kk].i + temp.i * a[idx_a_kk].r;
                temp.r = z__1.r; temp.i = z__1.i;
            }
            b[idx_b_kj].r = temp.r;
            b[idx_b_kj].i = temp.i;
        }
    }
}
}
