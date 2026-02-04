#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
integer *n;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

void init_vars() {
    const int N = 512;
    const int M = 512;

    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    a = (real*)calloc(N * N, sizeof(real));
    b = (real*)calloc(M * N, sizeof(real));

    *m = M;
    *n = N;
    *alpha = 1.5f;
    a_dim1 = N;
    b_dim1 = M;
    i__1 = N;
    nounit = 1;

    for (int col = 0; col < N; ++col) {
        for (int row = col; row < N; ++row) {
            a[row + col * a_dim1] = (real)(rand()) / RAND_MAX * 2.0f - 1.0f;
        }
    }

    for (int col = 0; col < N; ++col) {
        for (int row = 0; row < M; ++row) {
            b[row + col * b_dim1] = (real)(rand()) / RAND_MAX * 2.0f - 1.0f;
        }
    }
}