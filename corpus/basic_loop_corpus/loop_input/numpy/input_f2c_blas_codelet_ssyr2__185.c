#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *n;
real *alpha;
real *x;
real *y;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp1;
real temp2;

void init_vars() {
    const int N = 4096;
    const int data_size_a = N * N;
    const int data_size_xy = N;

    n = (integer*)malloc(sizeof(integer));
    alpha = (real*)malloc(sizeof(real));
    x = (real*)malloc(data_size_xy * sizeof(real));
    y = (real*)malloc(data_size_xy * sizeof(real));
    a = (real*)malloc(data_size_a * sizeof(real));

    *n = N;
    *alpha = 1.5f;
    a_dim1 = N;
    i__1 = N;
    temp1 = 0.0f;
    temp2 = 0.0f;
    i__ = 0;
    j = 0;
    i__2 = 0;

    for (int idx = 0; idx < data_size_xy; ++idx) {
        x[idx] = sinf(idx) != 0.0f ? sinf(idx) : 1.0f;
        y[idx] = cosf(idx) != 0.0f ? cosf(idx) : 1.0f;
    }

    for (int idx = 0; idx < data_size_a; ++idx) {
        a[idx] = 0.1f;
    }
}