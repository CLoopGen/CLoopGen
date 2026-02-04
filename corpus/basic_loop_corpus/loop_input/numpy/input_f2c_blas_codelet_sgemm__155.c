#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
integer *k;
real *alpha;
real *a;
real *b;
real *beta;
real *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp;

void init_vars() {
    // Set matrix dimensions
    const int M = 256;  // rows of a, rows of c
    const int N = 256;  // cols of b, cols of c
    const int K = 256;  // cols of a, rows of b

    // Allocate and initialize scalar pointers
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    beta = (real*)malloc(sizeof(real));

    *m = M;
    *k = K;
    *alpha = 1.2f;
    *beta = 0.8f;

    // Set loop bounds to ensure valid access
    i__1 = N;  // j from 1 to N
    i__2 = M;  // i from 1 to M
    i__3 = K;  // l from 1 to K

    // Set leading dimensions (assumed column-major)
    a_dim1 = M;
    b_dim1 = K;
    c_dim1 = M;

    // Allocate matrices with padding for 1-based indexing
    a = (real*)calloc((M * K + 1), sizeof(real));
    b = (real*)calloc((K * N + 1), sizeof(real));
    c__ = (real*)calloc((M * N + 1), sizeof(real));

    // Initialize a, b with non-zero values to ensure computation
    for (int idx = 1; idx <= M * K; ++idx) {
        a[idx] = (real)(rand() % 100) / 10.0f;
    }
    for (int idx = 1; idx <= K * N; ++idx) {
        b[idx] = (real)(rand() % 100) / 10.0f;
    }
    for (int idx = 1; idx <= M * N; ++idx) {
        c__[idx] = (real)(rand() % 100) / 10.0f;
    }

    // Initialize temp
    temp = 0.0f;
}