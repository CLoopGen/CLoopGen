#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
logical nounit;

void init_vars() {
    const int M = 1024;  
    const int N = 1024;  

    m = (integer*)malloc(sizeof(integer));
    *m = M;

    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    a_dim1 = M;
    b_dim1 = M;

    i__1 = N;
    nounit = 1;

    a = (doublereal*)calloc(M * M, sizeof(doublereal));
    b = (doublereal*)calloc(M * N, sizeof(doublereal));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i == j)
                a[i + j * a_dim1] = 2.0;
            else if (j < i)
                a[i + j * a_dim1] = drand48();
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            b[i + j * b_dim1] = drand48();
        }
    }
}