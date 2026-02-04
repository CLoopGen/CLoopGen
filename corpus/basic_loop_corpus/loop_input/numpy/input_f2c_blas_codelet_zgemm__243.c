#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *m;
integer *k;
doublecomplex *alpha;
doublecomplex *a;
doublecomplex *b;
doublecomplex *beta;
doublecomplex *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
integer i__6;
doublecomplex z__1;
doublecomplex z__2;
integer i__;
integer j;
integer l;
doublecomplex temp;

void init_vars() {
    // Set dimensions to control data size and runtime (~0.01 seconds)
    const int M = 512;   // *m
    const int K = 256;   // *k
    const int N = 512;   // i__1 (j-loop bound)

    // Allocate scalars
    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (doublecomplex*)malloc(sizeof(doublecomplex));
    beta = (doublecomplex*)malloc(sizeof(doublecomplex));

    *m = M;
    *k = K;
    alpha->r = 1.5; alpha->i = 0.5;
    beta->r = 0.8; beta->i = 0.2;

    // Set leading dimensions
    a_dim1 = M;
    b_dim1 = K;
    c_dim1 = M;
    i__1 = N;

    // Allocate matrices: column-major layout
    a = (doublecomplex*)malloc(M * K * sizeof(doublecomplex));
    b = (doublecomplex*)malloc(K * N * sizeof(doublecomplex));
    c__ = (doublecomplex*)malloc(M * N * sizeof(doublecomplex));

    // Initialize all matrices to non-zero values
    for (int i = 0; i < M * K; ++i) {
        a[i].r = (doublereal)(i % 7 + 1) / 7.0;
        a[i].i = (doublereal)(i % 5 + 1) / 5.0;
    }
    for (int i = 0; i < K * N; ++i) {
        b[i].r = (doublereal)(i % 6 + 1) / 6.0;
        b[i].i = (doublereal)(i % 4 + 1) / 4.0;
    }
    for (int i = 0; i < M * N; ++i) {
        c__[i].r = (doublereal)(i % 3 + 1) / 3.0;
        c__[i].i = (doublereal)(i % 2 + 1) / 2.0;
    }

    // Initialize temporaries to zero
    temp.r = 0.0; temp.i = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    i__2 = 0;
    i__3 = 0;
    i__4 = 0;
    i__5 = 0;
    i__6 = 0;
    i__ = 0;
    j = 0;
    l = 0;
}