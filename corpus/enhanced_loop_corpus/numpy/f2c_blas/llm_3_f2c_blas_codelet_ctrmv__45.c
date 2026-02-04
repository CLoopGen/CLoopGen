#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

typedef int logical;

extern singlecomplex *a;
extern singlecomplex *x;
extern integer *incx;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__5;
extern singlecomplex q__1;
extern singlecomplex q__2;
extern integer i__;
extern integer j;
extern integer ix;
extern integer jx;
extern integer kx;
extern singlecomplex temp;
extern logical nounit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    int offset_x = jx;
    if (x[offset_x].r != 0.F || x[offset_x].i != 0.F) {
        temp.r = x[offset_x].r;
        temp.i = x[offset_x].i;
        int ix_offset = kx;
        for (int i_val = 1; i_val <= j - 1; ++i_val) {
            int idx_a = i_val + j * a_dim1;
            int idx_x = ix_offset;
            singlecomplex product;
            product.r = temp.r * a[idx_a].r - temp.i * a[idx_a].i;
            product.i = temp.r * a[idx_a].i + temp.i * a[idx_a].r;
            x[idx_x].r += product.r;
            x[idx_x].i += product.i;
            ix_offset += *incx;
        }
        if (nounit) {
            int diag_idx_a = j + j * a_dim1;
            int idx_x_jx = jx;
            singlecomplex diag_product;
            diag_product.r = x[idx_x_jx].r * a[diag_idx_a].r - x[idx_x_jx].i * a[diag_idx_a].i;
            diag_product.i = x[idx_x_jx].r * a[diag_idx_a].i + x[idx_x_jx].i * a[diag_idx_a].r;
            x[idx_x_jx].r = diag_product.r;
            x[idx_x_jx].i = diag_product.i;
        }
    }
    jx += *incx;
}
}
