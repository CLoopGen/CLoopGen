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
for (int stride_j = 0; stride_j < i__1; ++stride_j) {
    int current_jx = kx + stride_j * (*incx);
    if (x[current_jx].r == 0.F && x[current_jx].i == 0.F) {
        continue;
    }
    temp.r = x[current_jx].r;
    temp.i = x[current_jx].i;
    for (int i_val = 0; i_val < stride_j; ++i_val) {
        int access_x = kx + i_val * (*incx);
        int access_a = (i_val + 1) + (stride_j + 1) * a_dim1;
        singlecomplex update;
        update.r = temp.r * a[access_a].r - temp.i * a[access_a].i;
        update.i = temp.r * a[access_a].i + temp.i * a[access_a].r;
        x[access_x].r += update.r;
        x[access_x].i += update.i;
    }
    if (nounit) {
        int diag_a_index = (stride_j + 1) + (stride_j + 1) * a_dim1;
        singlecomplex diag_mult;
        diag_mult.r = x[current_jx].r * a[diag_a_index].r - x[current_jx].i * a[diag_a_index].i;
        diag_mult.i = x[current_jx].r * a[diag_a_index].i + x[current_jx].i * a[diag_a_index].r;
        x[current_jx].r = diag_mult.r;
        x[current_jx].i = diag_mult.i;
    }
}
}
