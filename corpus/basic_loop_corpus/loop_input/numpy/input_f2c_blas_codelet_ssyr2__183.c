#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;

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
    const int size = 4096; 
    i__1 = size;
    a_dim1 = size;

    alpha = (real*)malloc(sizeof(real));
    *alpha = 1.5f;

    x = (real*)malloc((size + 1) * sizeof(real));
    y = (real*)malloc((size + 1) * sizeof(real));
    a = (real*)malloc((size + 1) * (size + 1) * sizeof(real));

    for (int idx = 0; idx <= size; ++idx) {
        x[idx] = sinf(idx);
        y[idx] = cosf(idx);
    }

    for (int i = 0; i <= size; ++i) {
        for (int j = 0; j <= size; ++j) {
            a[i + j * a_dim1] = 0.0f;
        }
    }

    i__ = 0;
    j = 0;
    temp1 = 0.0f;
    temp2 = 0.0f;
}