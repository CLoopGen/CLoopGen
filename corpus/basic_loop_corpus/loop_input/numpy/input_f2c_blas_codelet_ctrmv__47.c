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
integer *incx;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer ix;
integer jx;
integer kx;
singlecomplex temp;
logical nounit;

static singlecomplex *a_data;
static singlecomplex *x_data;

void init_vars() {
    const int N = 4096;
    const int alignment = 32;

    n = (integer*)aligned_alloc(alignment, sizeof(integer));
    incx = (integer*)aligned_alloc(alignment, sizeof(integer));
    
    *n = N;
    *incx = 1;
    a_dim1 = N;
    nounit = 1;

    size_t a_size = (size_t)N * N;
    size_t x_size = (size_t)N;

    a_data = (singlecomplex*)aligned_alloc(alignment, a_size * sizeof(singlecomplex));
    x_data = (singlecomplex*)aligned_alloc(alignment, x_size * sizeof(singlecomplex));

    a = a_data;
    x = x_data;

    for (size_t i = 0; i < a_size; ++i) {
        a_data[i].r = (real)(i % 127) / 127.0f;
        a_data[i].i = (real)((i * 7) % 127) / 127.0f;
    }

    for (size_t i = 0; i < x_size; ++i) {
        x_data[i].r = (real)(i % 53) / 53.0f;
        x_data[i].i = (real)((i * 3) % 53) / 53.0f;
    }

    jx = (N - 1) * (*incx);
    kx = jx;

    i__1 = i__2 = i__3 = i__4 = 0;
    temp.r = temp.i = 0.0f;
    ix = j = 0;
}