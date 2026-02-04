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
extern integer *incx;
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
extern integer ix;
extern integer jx;
extern integer kx;
extern doublecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change to consecutive memory access by precomputing base pointers and using linear indexing
doublecomplex *x_base = &x[kx]; // Base pointer for x starting at kx
integer stride_x = *incx;
for (j = 1; j <= i__1; ++j) {
    ptrdiff_t offset_jx = (j - 1) * stride_x; // Convert jx progression into linear offset
    if (x_base[offset_jx].r != 0. || x_base[offset_jx].i != 0.) {
        temp.r = x_base[offset_jx].r;
        temp.i = x_base[offset_jx].i;
        for (i__ = 1; i__ <= j - 1; ++i__) {
            ptrdiff_t offset_ix = (i__ - 1) * stride_x; // Consecutive access pattern in x
            ptrdiff_t a_index = i__ + j * a_dim1;      // Column-major access preserved in A
            z__2.r = temp.r * a[a_index].r - temp.i * a[a_index].i;
            z__2.i = temp.r * a[a_index].i + temp.i * a[a_index].r;
            z__1.r = x_base[offset_ix].r + z__2.r;
            z__1.i = x_base[offset_ix].i + z__2.i;
            x_base[offset_ix].r = z__1.r;
            x_base[offset_ix].i = z__1.i;
        }
        if (nounit) {
            ptrdiff_t diag_index = j + j * a_dim1;
            z__1.r = x_base[offset_jx].r * a[diag_index].r - x_base[offset_jx].i * a[diag_index].i;
            z__1.i = x_base[offset_jx].r * a[diag_index].i + x_base[offset_jx].i * a[diag_index].r;
            x_base[offset_jx].r = z__1.r;
            x_base[offset_jx].i = z__1.i;
        }
    }
}
}
