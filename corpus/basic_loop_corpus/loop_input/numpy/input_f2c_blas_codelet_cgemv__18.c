#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
singlecomplex *alpha;
singlecomplex *a;
singlecomplex *x;
integer *incx;
singlecomplex *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer iy;
integer jx;
integer ky;
singlecomplex temp;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * (1 << 20)) / sizeof(singlecomplex))

void init_vars() {
    // Allocate and initialize scalar parameters
    m = (integer*)malloc(sizeof(integer));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));
    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));

    *m = 2048;
    *incx = 1;
    *incy = 1;
    alpha->r = 1.5f;
    alpha->i = 0.5f;

    // Set matrix dimension
    a_dim1 = *m;

    // Set loop bound i__1 to control outer loop iterations
    i__1 = 1024;

    // Allocate arrays with sufficient size to avoid out-of-bounds access
    x = (singlecomplex*)calloc(TOTAL_ELEMENTS, sizeof(singlecomplex));
    y = (singlecomplex*)calloc(TOTAL_ELEMENTS, sizeof(singlecomplex));
    a = (singlecomplex*)calloc(TOTAL_ELEMENTS, sizeof(singlecomplex));

    // Initialize x with non-zero values in accessible range to trigger conditional branch
    for (int idx = 0; idx < i__1; ++idx) {
        x[idx * (*incx)].r = sinf(idx);
        x[idx * (*incx)].i = cosf(idx);
    }

    // Initialize a matrix (m x i__1) with meaningful data
    for (int jj = 0; jj <= i__1; ++jj) {
        for (int ii = 0; ii < *m; ++ii) {
            a[ii + jj * a_dim1].r = 1.0f / (1.0f + ii + jj);
            a[ii + jj * a_dim1].i = -a[ii + jj * a_dim1].r;
        }
    }

    // Precompute initial index offsets
    jx = 0;
    ky = 0;
}