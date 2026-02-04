#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
integer *n;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

void init_vars() {
    const int N = 512;
    const int M = 512;

    m = (integer*)malloc(sizeof(integer));
    n = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    
    *m = M;
    *n = N;
    *alpha = 1.5;
    a_dim1 = N;
    b_dim1 = M;
    nounit = 1;

    size_t a_size = (size_t)N * N;
    size_t b_size = (size_t)M * N;
    
    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    b = (doublereal*)calloc(b_size, sizeof(doublereal));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            a[i + j * a_dim1] = sin((i + j) * 0.1);
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            b[i + j * b_dim1] = cos((i - j) * 0.05);
        }
    }
}