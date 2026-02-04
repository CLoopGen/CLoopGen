#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
real *alpha;
real *a;
real *x;
integer *incx;
real *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer iy;
integer jx;
integer ky;
real temp;

void init_vars() {
    // Set problem size parameters
    const int M = 4096;        // rows of matrix 'a'
    const int N = 4096;        // cols of matrix 'a', and length related to loop bound i__1
    const int INCX = 1;
    const int INCY = 1;
    const float ALPHA_VAL = 1.5f;

    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    incx = (integer*)malloc(sizeof(integer));
    incy = (integer*)malloc(sizeof(integer));

    *m = M;
    *alpha = ALPHA_VAL;
    *incx = INCX;
    *incy = INCY;
    a_dim1 = M;  // leading dimension of matrix 'a'
    i__1 = N;    // outer loop bound: j from 1 to N

    // Allocate arrays with proper sizes (1-based indexing used in loops)
    // x has at least N elements accessed via jx with increment incx
    x = (real*)calloc(N * abs(*incx) + 1, sizeof(real));
    y = (real*)calloc(M * abs(*incy) + 1, sizeof(real));
    // a is M x N matrix stored in column-major order: [i + j*a_dim1], a_dim1 = M
    a = (real*)malloc(M * N * sizeof(real));

    // Initialize pointers used in loop
    jx = 1;  // starting index for x vector (1-based)
    ky = 1;  // base index for y when j=1
    iy = 0;  // will be set inside loop

    // Initialize data content
    for (int i = 0; i < M * N; ++i) {
        a[i] = (real)(rand() % 100) / 10.0f;
    }
    for (int i = 1; i <= N; ++i) {
        x[(i-1)*(*incx)+1] = (rand() % 2) ? (real)(rand() % 10) / 5.0f : 0.0f;
    }
    for (int i = 1; i <= M; ++i) {
        y[(i-1)*(*incy)+1] = (real)(rand() % 100) / 10.0f;
    }

    temp = 0.0f;
}