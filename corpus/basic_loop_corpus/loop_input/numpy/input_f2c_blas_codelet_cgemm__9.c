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

integer *m;
integer *k;
singlecomplex *alpha;
singlecomplex *a;
singlecomplex *b;
singlecomplex *beta;
singlecomplex *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
integer i__6;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer l;
singlecomplex temp;

void init_vars() {
    // Set problem dimensions
    const int M = 200;
    const int K = 150;
    const int N = 100;

    // Allocate and initialize scalar parameters
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    *m = M;
    *k = K;

    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta  = (singlecomplex*)malloc(sizeof(singlecomplex));
    alpha->r = 1.5f; alpha->i = 0.5f;
    beta->r  = 0.8f; beta->i  = 0.2f;

    // Set loop bound for outermost loop: j <= i__1 => i__1 = N
    i__1 = N;

    // Matrix dimensions
    a_dim1 = M;
    b_dim1 = K;
    c_dim1 = M;

    // Allocate matrices in column-major layout (Fortran-style)
    a = (singlecomplex*)calloc(M * K, sizeof(singlecomplex));
    b = (singlecomplex*)calloc(K * N, sizeof(singlecomplex));
    c__ = (singlecomplex*)calloc(M * N, sizeof(singlecomplex));

    // Initialize a and b with non-zero values to ensure computation happens
    for (int i = 0; i < M * K; ++i) {
        a[i].r = (real)(i % 7 + 1) / 7.0f;
        a[i].i = (real)(i % 5 + 1) / 5.0f;
    }
    for (int i = 0; i < K * N; ++i) {
        b[i].r = (real)(i % 6 + 1) / 6.0f;
        b[i].i = (real)(i % 4 + 1) / 4.0f;
    }
    for (int i = 0; i < M * N; ++i) {
        c__[i].r = (real)(i % 3 + 1) / 3.0f;
        c__[i].i = (real)(i % 2 + 1) / 2.0f;
    }

    // Initialize temporaries to zero
    temp.r = 0.0f; temp.i = 0.0f;
    q__1.r = 0.0f; q__1.i = 0.0f;
    q__2.r = 0.0f; q__2.i = 0.0f;
}