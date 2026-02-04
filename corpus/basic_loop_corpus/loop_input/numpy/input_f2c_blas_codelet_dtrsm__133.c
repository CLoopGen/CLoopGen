#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

#define N 1000
#define M 256

void init_vars() {
    m = (integer*)malloc(sizeof(integer));
    alpha = (doublereal*)malloc(sizeof(doublereal));
    a = (doublereal*)calloc(N * N, sizeof(doublereal));
    b = (doublereal*)calloc(M * N, sizeof(doublereal));
    
    *m = M;
    *alpha = 1.2;
    a_dim1 = N;
    b_dim1 = M;
    i__1 = N;
    nounit = 1;

    for (int col = 0; col < N; ++col) {
        for (int row = 0; row <= col; ++row) {
            a[row + col * a_dim1] = sin((row + 1) * 0.1) * cos((col + 1) * 0.1);
        }
        if (a[col + col * a_dim1] == 0.0) {
            a[col + col * a_dim1] = 1.0;
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < M; ++i) {
            b[i + j * b_dim1] = ((doublereal)rand() / RAND_MAX) * 2.0 - 1.0;
        }
    }
}