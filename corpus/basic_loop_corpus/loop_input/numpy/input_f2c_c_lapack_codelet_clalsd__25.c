#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *n;
singlecomplex *b;
real *rwork;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer j;
integer jcol;
integer jrow;

void init_vars() {
    const int size_n = 8000;
    const int num_cols = 8000;

    n = (integer*)malloc(sizeof(integer));
    *n = size_n;

    b_dim1 = size_n;
    i__1 = num_cols;

    b = (singlecomplex*)calloc((size_t)(b_dim1 * num_cols + 1), sizeof(singlecomplex));
    rwork = (real*)malloc(sizeof(real) * (size_t)(size_n * num_cols + 10));

    j = 0;

    for (int i = 0; i <= b_dim1 * num_cols; ++i) {
        b[i].r = (real)(i % 1000) / 100.0f;
        b[i].i = 0.0f;
    }

    i__2 = *n;
    i__3 = 0;
    jcol = 0;
    jrow = 0;
}