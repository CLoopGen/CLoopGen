#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

singlecomplex *cx;
integer *incx;
singlecomplex *cy;
integer *incy;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer ix;
integer iy;
singlecomplex ctemp;

void init_vars() {
    const size_t N = 1 << 20; // 1M elements, roughly 16MB total for cx and cy

    // Allocate arrays
    cx = (singlecomplex*)aligned_alloc(32, N * sizeof(singlecomplex));
    cy = (singlecomplex*)aligned_alloc(32, N * sizeof(singlecomplex));
    incx = (integer*)aligned_alloc(32, sizeof(integer));
    incy = (integer*)aligned_alloc(32, sizeof(integer));

    // Initialize increment values
    *incx = 1;
    *incy = 1;

    // Set loop bounds to ensure no out-of-bounds access
    // i__1 should be such that ix + (i__1 - 1)*(*incx) < N
    // Assuming initial ix = 0, then i__1 <= (N - ix + *incx - 1) / *incx
    ix = 0;
    iy = 0;
    i__1 = N - 1; // Safe upper bound for increments of 1

    // Initialize array data with non-zero values for meaningful computation
    for (size_t i = 0; i < N; ++i) {
        cx[i].r = sinf((float)i);
        cx[i].i = cosf((float)i);
        cy[i].r = cosf((float)(i * 1.5f));
        cy[i].i = sinf((float)(i * 1.5f));
    }

    // Initialize accumulators
    ctemp.r = 0.0f;
    ctemp.i = 0.0f;

    // Ensure compiler doesn't optimize based on predictable patterns
    // by using volatile or runtime-dependent initialization if needed.
    // Here we use fixed seed for reproducibility.
}