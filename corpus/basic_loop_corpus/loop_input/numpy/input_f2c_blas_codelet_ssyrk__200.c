#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *n;
integer *k;
real *alpha;
real *a;
real *beta;
real *c__;
integer a_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp;

void init_vars() {
    const int N = 1024;  
    const int K = 512;

    n = (integer*)malloc(sizeof(integer));
    k = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    beta = (real*)malloc(sizeof(real));

    *n = N;
    *k = K;
    *alpha = 1.5f;
    *beta = 0.5f;

    a_dim1 = N;
    c_dim1 = N;

    i__1 = N;
    i__2 = N;
    i__3 = N;

    a = (real*)calloc((N + 1) * (K + 1), sizeof(real));
    c__ = (real*)calloc((N + 1) * (N + 1), sizeof(real));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            a[i + j * a_dim1] = (real)(i % 17 + j % 19) / 10.0f;
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            c__[i + j * c_dim1] = (real)(i % 13 + j % 17) / 5.0f;
        }
    }

    temp = 0.0f;
    i__ = 1;
    j = 1;
    l = 1;
}