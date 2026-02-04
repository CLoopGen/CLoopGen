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

typedef int logical;

integer *n;
singlecomplex *a;
singlecomplex *x;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
singlecomplex temp;
logical nounit;

void init_vars() {
    const int data_size = 8192;
    n = (integer*)malloc(sizeof(integer));
    *n = data_size;

    a_dim1 = data_size;
    size_t a_size = (size_t)data_size * data_size;
    a = (singlecomplex*)calloc(a_size, sizeof(singlecomplex));
    x = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));

    nounit = 1;

    for (int idx = 0; idx < data_size; ++idx) {
        x[idx].r = sinf(idx % 100);
        x[idx].i = cosf(idx % 100);
    }

    for (size_t idx = 0; idx < a_size; ++idx) {
        a[idx].r = rand() / (real)RAND_MAX;
        a[idx].i = rand() / (real)RAND_MAX;
    }
}