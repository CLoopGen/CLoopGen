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
    const integer M = 512;
    const integer K = 512;
    const integer N = 512;

    m = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    *m = M;
    *k = K;

    alpha = (singlecomplex*)malloc(sizeof(singlecomplex));
    beta = (singlecomplex*)malloc(sizeof(singlecomplex));
    alpha->r = 1.5f;
    alpha->i = 0.5f;
    beta->r = 1.0f;
    beta->i = 0.0f;

    a_dim1 = M;
    b_dim1 = K;
    c_dim1 = M;

    i__1 = N;

    a = (singlecomplex*)calloc(M * K, sizeof(singlecomplex));
    b = (singlecomplex*)calloc(K * N, sizeof(singlecomplex));
    c__ = (singlecomplex*)calloc(M * N, sizeof(singlecomplex));

    for (integer idx = 0; idx < M * K; ++idx) {
        a[idx].r = (real)(drand48());
        a[idx].i = (real)(drand48());
    }

    for (integer idx = 0; idx < K * N; ++idx) {
        b[idx].r = (real)(drand48() - 0.5) * 2.0;
        b[idx].i = (real)(drand48() - 0.5) * 2.0;
    }

    for (integer idx = 0; idx < M * N; ++idx) {
        c__[idx].r = (real)(drand48());
        c__[idx].i = (real)(drand48());
    }
}