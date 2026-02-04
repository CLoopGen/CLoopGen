#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *x;
integer *incx;
doublereal *y;
integer *incy;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer ix;
integer jy;
integer kx;
doublereal temp;

void init_vars() {
    const integer M = 4096;
    const integer N = 4096;

    m = (integer*)malloc(sizeof(integer));
    *m = M;

    alpha = (doublereal*)malloc(sizeof(doublereal));
    *alpha = 1.5;

    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;

    incy = (integer*)malloc(sizeof(integer));
    *incy = 1;

    a_dim1 = M;
    i__1 = N;

    a = (doublereal*)calloc((size_t)(M * N), sizeof(doublereal));
    x = (doublereal*)calloc((size_t)(M), sizeof(doublereal));
    y = (doublereal*)calloc((size_t)(N), sizeof(doublereal));

    for (integer i = 0; i < M; ++i) {
        x[i] = sin(i * 0.01);
    }

    for (integer i = 0; i < M; ++i) {
        for (integer j = 0; j < N; ++j) {
            a[i + j * a_dim1] = sin((i - j) * 0.001);
        }
    }

    for (integer j = 0; j < N; ++j) {
        y[j] = cos(j * 0.01);
    }

    kx = 0;
    jy = 0;
    i__ = 0;
    j = 0;
    ix = 0;
    temp = 0.0;
}