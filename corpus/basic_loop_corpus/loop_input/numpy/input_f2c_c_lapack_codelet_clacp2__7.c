#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
real *a;
singlecomplex *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__;
integer j;

void init_vars() {
    const integer data_size = 8192;
    const integer matrix_size = data_size * data_size;

    m = (integer*)malloc(sizeof(integer));
    *m = data_size;

    a_dim1 = data_size;
    b_dim1 = data_size;
    i__1 = data_size;

    a = (real*)calloc(matrix_size, sizeof(real));
    b = (singlecomplex*)calloc(matrix_size, sizeof(singlecomplex));

    for (integer idx = 0; idx < matrix_size; ++idx) {
        a[idx] = (real)(idx % 1000) / 10.0f;
    }
}