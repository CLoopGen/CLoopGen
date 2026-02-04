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
// Variant 2: Strided memory access with reversed loop order and strided traversal
// We reverse the loop bounds and access array elements using fixed stride jumps
integer j_rev, i_rev, l_rev;
integer stride_c = c_dim1, stride_b = b_dim1, stride_a = a_dim1;

for (j_rev = i__1; j_rev >= 1; --j_rev) {
    integer cj_offset = j_rev * stride_c;

    if (beta->r == 0. && beta->i == 0.) {
        for (i_rev = *m; i_rev >= 1; --i_rev) {
            integer idx = i_rev + cj_offset;
            c__[idx].r = 0.0;
            c__[idx].i = 0.0;
        }
    } else if (beta->r != 1. || beta->i != 0.) {
        for (i_rev = *m; i_rev >= 1; --i_rev) {
            integer idx = i_rev + cj_offset;
            z__1.r = beta->r * c__[idx].r - beta->i * c__[idx].i;
            z__1.i = beta->r * c__[idx].i + beta->i * c__[idx].r;
            c__[idx].r = z__1.r;
            c__[idx].i = z__1.i;
        }
    }

    for (l_rev = *k; l_rev >= 1; --l_rev) {
        integer blj_offset = j_rev + l_rev * stride_b;
        if (b[blj_offset].r != 0. || b[blj_offset].i != 0.) {
            z__1.r = alpha->r * b[blj_offset].r - alpha->i * b[blj_offset].i;
            z__1.i = alpha->r * b[blj_offset].i + alpha->i * b[blj_offset].r;
            temp.r = z__1.r;
            temp.i = z__1.i;

            integer al_offset = l_rev * stride_a;
            for (i_rev = *m; i_rev >= 1; --i_rev) {
                integer ci_idx = i_rev + cj_offset;
                integer ai_idx = i_rev + al_offset;
                z__2.r = temp.r * a[ai_idx].r - temp.i * a[ai_idx].i;
                z__2.i = temp.r * a[ai_idx].i + temp.i * a[ai_idx].r;

                z__1.r = c__[ci_idx].r + z__2.r;
                z__1.i = c__[ci_idx].i + z__2.i;

                c__[ci_idx].r = z__1.r;
                c__[ci_idx].i = z__1.i;
            }
        }
    }
}
}
