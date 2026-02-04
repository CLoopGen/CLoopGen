#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *alpha;
extern singlecomplex *a;
extern singlecomplex *x;
extern integer *incx;
extern singlecomplex *y;
extern integer *incy;
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
extern integer iy;
extern integer jx;
extern integer ky;
extern singlecomplex temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Indirect memory access using index arrays to simulate gather operations
integer* restrict index_x = (integer*)alloca(i__1 * sizeof(integer));
integer* restrict index_y = (integer*)alloca(*m * sizeof(integer));
integer* restrict index_a = (integer*)alloca((*m) * sizeof(integer));

// Precompute indirect indices for x, y, and column of A
for (integer jj = 0; jj < i__1; ++jj) {
    index_x[jj] = 1 + jj * (*incx);
}
for (integer ii = 0; ii < *m; ++ii) {
    index_y[ii] = ky + ii * (*incy);
}

for (j = 1; j <= i__1; ++j) {
    integer j_idx = j - 1;
    integer x_idx = index_x[j_idx] - 1;
    if (x[x_idx].r != 0.F || x[x_idx].i != 0.F) {
        q__1.r = alpha->r * x[x_idx].r - alpha->i * x[x_idx].i;
        q__1.i = alpha->r * x[x_idx].i + alpha->i * x[x_idx].r;
        temp.r = q__1.r; temp.i = q__1.i;
        // Precompute row indices in A for current j
        for (integer ii = 1; ii <= *m; ++ii) {
            index_a[ii-1] = ii + j * a_dim1 - 1; // Convert to zero-based
        }
        for (i__ = 1; i__ <= *m; ++i__) {
            integer iy = index_y[i__-1] - 1;
            integer ia = index_a[i__-1];
            q__2.r = temp.r * a[ia].r - temp.i * a[ia].i;
            q__2.i = temp.r * a[ia].i + temp.i * a[ia].r;
            y[iy].r += q__2.r;
            y[iy].i += q__2.i;
        }
    }
}
}
