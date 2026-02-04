#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

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
integer ix;
integer jy;
integer kx;
real temp;

void init_vars() {
    const int M = 4096;
    const int N = 4096;

    m = (integer*)malloc(sizeof(integer));
    *m = M;
    a_dim1 = M;

    i__1 = N;

    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.5f;

    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    a = (real*)malloc((M * N) * sizeof(real));
    x = (real*)malloc(M * sizeof(real));
    y = (real*)calloc(N, sizeof(real));

    kx = 0;
    jy = 0;

    for (int i = 0; i < M; ++i) {
        x[i] = (real)(i % 128) / 64.0f;
    }

    for (int i = 0; i < M * N; ++i) {
        a[i] = (real)(rand() % 100) / 100.0f;
    }

    for (int i = 0; i < N; ++i) {
        y[i] = (real)(rand() % 100) / 50.0f;
    }
}