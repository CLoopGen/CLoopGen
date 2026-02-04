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

integer m_data = 512;
integer n_data = 512;
singlecomplex alpha_data = {1.5f, -0.8f};
singlecomplex *a_data;
singlecomplex *b_data;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
integer i__5;
singlecomplex q__1;
singlecomplex q__2;
integer i__;
integer j;
integer k;
singlecomplex temp;
logical nounit = 0;

integer *m = &m_data;
integer *n = &n_data;
singlecomplex *alpha = &alpha_data;
singlecomplex *a = NULL;
singlecomplex *b = NULL;
integer a_dim1_data;
integer b_dim1_data;

void init_vars() {
    a_dim1 = *n;
    b_dim1 = *n;
    a_dim1_data = a_dim1;
    b_dim1_data = b_dim1;

    a_data = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * (*n) * a_dim1);
    b_data = (singlecomplex*)aligned_alloc(32, sizeof(singlecomplex) * (*m) * b_dim1);

    a = a_data;
    b = b_data;

    for (int idx = 0; idx < *n * a_dim1; ++idx) {
        a_data[idx].r = sinf(idx * 0.01f);
        a_data[idx].i = cosf(idx * 0.01f);
    }

    for (int idx = 0; idx < *m * b_dim1; ++idx) {
        b_data[idx].r = 0.5f + sinf(idx * 0.02f) * 0.3f;
        b_data[idx].i = 0.5f + cosf(idx * 0.02f) * 0.3f;
    }

    nounit = (*n % 2);
}