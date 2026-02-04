#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;

integer n_storage = 1024;
integer k_storage = 512;
real alpha_storage = 1.5f;
real beta_storage = 1.0f;

integer a_dim1 = 512;
integer b_dim1 = 512;
integer c_dim1 = 1024;

integer i__1 = 512;
integer i__2 = 0;
integer i__3 = 0;
integer i__ = 0;
integer j = 0;
integer l = 0;

real temp1 = 0.0f;
real temp2 = 0.0f;

real *a;
real *b;
real *c__;
real *alpha = &alpha_storage;
real *beta = &beta_storage;
integer *n = &n_storage;
integer *k = &k_storage;

void init_vars() {
    const size_t a_size = (size_t)(i__1 + 1) * (k_storage + 1);
    const size_t b_size = (size_t)(i__1 + 1) * (k_storage + 1);
    const size_t c_size = (size_t)(n_storage + 1) * (i__1 + 1);

    a = (real*)calloc(a_size, sizeof(real));
    b = (real*)calloc(b_size, sizeof(real));
    c__ = (real*)calloc(c_size, sizeof(real));

    if (!a || !b || !c__) {
        exit(1);
    }

    for (int idx = 0; idx < a_size; ++idx) {
        a[idx] = sinf((float)(idx % 100)) * 0.01f;
    }
    for (int idx = 0; idx < b_size; ++idx) {
        b[idx] = cosf((float)(idx % 100)) * 0.01f;
    }
    for (int idx = 0; idx < c_size; ++idx) {
        c__[idx] = (rand() % 1000) * 0.001f;
    }
}