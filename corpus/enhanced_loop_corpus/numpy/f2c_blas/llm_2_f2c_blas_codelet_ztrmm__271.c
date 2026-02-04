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
    for (k = *m; k >= 1; --k) {
        ptrdiff_t idx_b_kj = (ptrdiff_t)k + (ptrdiff_t)j * b_dim1;
        if (b[idx_b_kj].r != 0. || b[idx_b_kj].i != 0.) {
            z__1.r = alpha->r * b[idx_b_kj].r - alpha->i * b[idx_b_kj].i;
            z__1.i = alpha->r * b[idx_b_kj].i + alpha->i * b[idx_b_kj].r;
            temp.r = z__1.r; temp.i = z__1.i;
            b[idx_b_kj].r = temp.r; b[idx_b_kj].i = temp.i;
            if (nounit) {
                ptrdiff_t idx_a_kk = (ptrdiff_t)k + (ptrdiff_t)k * a_dim1;
                z__1.r = b[idx_b_kj].r * a[idx_a_kk].r - b[idx_b_kj].i * a[idx_a_kk].i;
                z__1.i = b[idx_b_kj].r * a[idx_a_kk].i + b[idx_b_kj].i * a[idx_a_kk].r;
                b[idx_b_kj].r = z__1.r; b[idx_b_kj].i = z__1.i;
            }
            for (i__ = k + 1; i__ <= *m; ++i__) {
                ptrdiff_t idx_b_ij = (ptrdiff_t)i__ + (ptrdiff_t)j * b_dim1;
                ptrdiff_t idx_a_ik = (ptrdiff_t)i__ + (ptrdiff_t)k * a_dim1;
                z__2.r = temp.r * a[idx_a_ik].r - temp.i * a[idx_a_ik].i;
                z__2.i = temp.r * a[idx_a_ik].i + temp.i * a[idx_a_ik].r;
                b[idx_b_ij].r += z__2.r;
                b[idx_b_ij].i += z__2.i;
            }
        }
    }
}
}
