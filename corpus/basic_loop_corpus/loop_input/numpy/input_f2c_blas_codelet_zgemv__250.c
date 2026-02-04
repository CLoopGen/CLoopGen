#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
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
integer *incy;
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
integer iy;
integer jx;
integer ky;
doublecomplex temp;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, choose M and N around 1000-2000
    const int M = 1500;
    const int N = 1500;

    // Allocate and initialize scalar variables
    m = (integer*)malloc(sizeof(integer));
    *m = M;

    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    a_dim1 = M;  // leading dimension of matrix a

    i__1 = N;  // outer loop bound (number of columns in A, length of x)

    // Allocate arrays
    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    alpha->r = 1.5;
    alpha->i = 0.5;

    a = (doublecomplex*)malloc((size_t)M * N * sizeof(doublecomplex));
    x = (doublecomplex*)malloc((size_t)N * sizeof(doublecomplex));
    y = (doublecomplex*)malloc((size_t)M * sizeof(doublecomplex));

    // Initialize arrays with non-zero values to ensure execution through all branches
    for (int i = 0; i < M * N; ++i) {
        a[i].r = sin(i * 0.01);
        a[i].i = cos(i * 0.01);
    }

    for (int i = 0; i < N; ++i) {
        x[i].r = sin(i * 0.1);
        x[i].i = cos(i * 0.1);
    }

    for (int i = 0; i < M; ++i) {
        y[i].r = i * 0.01;
        y[i].i = -i * 0.01;
    }

    // Initialize loop indices and auxiliary variables
    j = 1;
    jx = 0;  // base index for x (0-based in C, but algorithm uses 1-based logic)
    ky = 0;  // ky = &y[0] offset

    // Ensure temp and temporaries are zeroed
    temp.r = 0.0;
    temp.i = 0.0;
    z__1.r = 0.0;
    z__1.i = 0.0;
    z__2.r = 0.0;
    z__2.i = 0.0;
}