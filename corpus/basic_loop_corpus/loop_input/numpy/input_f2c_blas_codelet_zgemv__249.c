#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
doublecomplex *alpha;
doublecomplex *a;
doublecomplex *x;
integer *incx;
doublecomplex *y;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer jx;
doublecomplex temp;

void init_vars() {
    // Set problem size to achieve ~0.01 sec runtime
    // Based on typical performance, choose M and N such that total operations are moderate
    const integer M = 512;   // rows of matrix A, length of vectors x, y
    const integer N = 256;   // cols of matrix A, number of iterations in outer loop
    a_dim1 = M;              // leading dimension of A
    i__1 = N;                // upper bound for j loop
    *m = M;                  // bound for inner i loop

    *incx = 1;               // increment for x vector access

    // Allocate memory
    a = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex) * M * N);
    x = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex) * (1 + (N - 1) * abs(*incx)));
    y = (doublecomplex*)aligned_alloc(32, sizeof(doublecomplex) * M);
    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    
    // Initialize scalar values
    alpha->r = 1.5;
    alpha->i = 0.5;

    // Initialize arrays with non-zero data to ensure full execution path
    for (integer i = 0; i < M; ++i) {
        y[i].r = 0.1 * i;
        y[i].i = 0.05 * i;
    }

    jx = 1; // initial index for x, adjusted for 1-based indexing in loop logic

    for (integer j = 0; j < N; ++j) {
        integer idx_x = jx - 1; // convert to 0-based
        if (idx_x >= 0 && idx_x < (1 + (N - 1) * abs(*incx))) {
            x[idx_x].r = (j % 2 == 0) ? 0.0 : 0.2; // some zero, some non-zero
            x[idx_x].i = (j % 3 == 0) ? 0.1 : 0.0;
        }
        jx += *incx;
    }

    jx = 1; // reset for loop usage

    for (integer i = 0; i < M; ++i) {
        for (integer j = 0; j < N; ++j) {
            integer idx = i + j * a_dim1;
            a[idx].r = sin(i + j) * 0.01;
            a[idx].i = cos(i + j) * 0.01;
        }
    }
}

// Definitions must be allocated at file scope
integer m_storage = 0;
integer incx_storage = 0;

// Assign pointers to point to storage
integer* m = &m_storage;
integer* incx = &incx_storage;
doublecomplex* alpha = NULL;
doublecomplex* a = NULL;
doublecomplex* x = NULL;
doublecomplex* y = NULL;