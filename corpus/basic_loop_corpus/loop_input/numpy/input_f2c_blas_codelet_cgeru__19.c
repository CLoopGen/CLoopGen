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
singlecomplex *x;
singlecomplex *y;
integer *incy;
singlecomplex *a;
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
integer jy;
singlecomplex temp;

void init_vars() {
    // Problem size parameters
    const integer M = 2048;  // rows of matrix a and length of vector x
    const integer N = 512;   // columns of matrix a and loop count (i__1)
    
    // Set derived values
    a_dim1 = M;              // leading dimension of matrix a
    i__1 = N;                // upper bound for j loop
    m = (integer*)malloc(sizeof(integer));
    *m = M;
    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    // Allocate alpha
    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    alpha->r = 1.5f;
    alpha->i = 0.5f;

    // Allocate and initialize vectors
    x = (singlecomplex*)calloc(M, sizeof(singlecomplex));
    y = (singlecomplex*)calloc(N * abs(*incy), sizeof(singlecomplex)); // ensure enough space

    // Initialize x with non-zero data
    for (integer idx = 0; idx < M; ++idx) {
        x[idx].r = sinf(idx);
        x[idx].i = cosf(idx);
    }

    // Initialize y with mixed zero/non-zero entries to trigger the condition
    for (integer idx = 0; idx < N; ++idx) {
        if (idx % 3 == 0) {  // every third element non-zero
            y[idx].r = 0.5f * sinf(idx * 0.1f);
            y[idx].i = 0.5f * cosf(idx * 0.1f);
        } else {
            y[idx].r = 0.0f;
            y[idx].i = 0.0f;
        }
    }

    // Allocate and initialize matrix a
    a = (singlecomplex*)calloc(M * N, sizeof(singlecomplex));
    for (integer idx = 0; idx < M * N; ++idx) {
        a[idx].r = rand() / (real)RAND_MAX;
        a[idx].i = rand() / (real)RAND_MAX;
    }

    // Initialize loop index variables
    j = 1;
    jy = 1;  // initial offset into y (1-based indexing)

    // Initialize temp and temporaries
    temp.r = 0.0f;
    temp.i = 0.0f;
    q__1.r = 0.0f;
    q__1.i = 0.0f;
    q__2.r = 0.0f;
    q__2.i = 0.0f;
}