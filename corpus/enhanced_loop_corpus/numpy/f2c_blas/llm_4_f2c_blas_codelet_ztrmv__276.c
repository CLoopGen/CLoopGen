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

extern integer *n;
extern doublecomplex *a;
extern doublecomplex *x;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern doublecomplex z__1;
extern doublecomplex z__2;
extern integer i__;
extern integer j;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *n; j >= 1; --j) {
    ptrdiff_t x_idx = (ptrdiff_t)j;  // Use derived index to enable potential vectorization or prefetching
    if (x[x_idx].r != 0. || x[x_idx].i != 0.) {
        temp.r = x[x_idx].r;
        temp.i = x[x_idx].i;
        for (i__ = *n; i__ >= j + 1; --i__) {
            ptrdiff_t x_i_idx = (ptrdiff_t)i__;           // Base address offset for x[i]
            ptrdiff_t a_ij_idx = (ptrdiff_t)(i__) + (ptrdiff_t)(j) * a_dim1;  // Stride access with explicit scaling
            doublecomplex t;
            t.r = temp.r * a[a_ij_idx].r - temp.i * a[a_ij_idx].i;
            t.i = temp.r * a[a_ij_idx].i + temp.i * a[a_ij_idx].r;
            x[x_i_idx].r += t.r;
            x[x_i_idx].i += t.i;
        }
        if (nounit) {
            ptrdiff_t a_jj_idx = (ptrdiff_t)(j + j * a_dim1);
            ptrdiff_t x_j_idx = (ptrdiff_t)j;
            doublecomplex diag;
            diag.r = x[x_j_idx].r * a[a_jj_idx].r - x[x_j_idx].i * a[a_jj_idx].i;
            diag.i = x[x_j_idx].r * a[a_jj_idx].i + x[x_j_idx].i * a[a_jj_idx].r;
            x[x_j_idx].r = diag.r;
            x[x_j_idx].i = diag.i;
        }
    }
}
}
