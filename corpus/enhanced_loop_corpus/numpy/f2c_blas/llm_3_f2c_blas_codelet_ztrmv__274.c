#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

typedef int logical;

extern doublecomplex *a;
extern doublecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t x_idx = (ptrdiff_t)j;
    if (x[x_idx].r != 0. || x[x_idx].i != 0.) {
        temp.r = x[x_idx].r;
        temp.i = x[x_idx].i;
        for (i__ = 1; i__ <= j - 1; ++i__) {
            ptrdiff_t a_idx = (ptrdiff_t)(i__ + j * a_dim1);
            ptrdiff_t x_i_idx = (ptrdiff_t)i__;
            z__2.r = temp.r * a[a_idx].r - temp.i * a[a_idx].i;
            z__2.i = temp.r * a[a_idx].i + temp.i * a[a_idx].r;
            z__1.r = x[x_i_idx].r + z__2.r;
            z__1.i = x[x_i_idx].i + z__2.i;
            x[x_i_idx].r = z__1.r;
            x[x_i_idx].i = z__1.i;
        }
        if (nounit) {
            ptrdiff_t diag_a_idx = (ptrdiff_t)(j + j * a_dim1);
            ptrdiff_t x_j_idx = (ptrdiff_t)j;
            z__1.r = x[x_j_idx].r * a[diag_a_idx].r - x[x_j_idx].i * a[diag_a_idx].i;
            z__1.i = x[x_j_idx].r * a[diag_a_idx].i + x[x_j_idx].i * a[diag_a_idx].r;
            x[x_j_idx].r = z__1.r;
            x[x_j_idx].i = z__1.i;
        }
    }
}
}
