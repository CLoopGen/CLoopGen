#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef float real;

integer n_storage = 500;
integer k_storage = 400;
real alpha_storage = 1.5f;
real beta_storage = 0.5f;

integer a_dim1 = 500;
integer b_dim1 = 500;
integer c_dim1 = 500;

integer i__1 = 500;
integer i__2;
integer i__3;
integer i__ = 0;
integer j = 0;
integer l = 0;
real temp1 = 0.0f;
real temp2 = 0.0f;

real *a = NULL;
real *b = NULL;
real *c__ = NULL;

integer *n = &n_storage;
integer *k = &k_storage;
real *alpha = &alpha_storage;
real *beta = &beta_storage;

void init_vars() {
    const size_t a_size = (size_t)(a_dim1 + 1) * (size_t)(*n + 1);
    const size_t b_size = (size_t)(b_dim1 + 1) * (size_t)(*n + 1);
    const size_t c_size = (size_t)(c_dim1 + 1) * (size_t)(*n + 1);

    a = (real*)calloc(a_size, sizeof(real));
    b = (real*)calloc(b_size, sizeof(real));
    c__ = (real*)calloc(c_size, sizeof(real));

    if (!a || !b || !c__) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < a_size; ++i) {
        a[i] = sinf((float)(i % 100)) * 0.01f;
    }
    for (size_t i = 0; i < b_size; ++i) {
        b[i] = cosf((float)(i % 100)) * 0.01f;
    }
    for (size_t i = 0; i < c_size; ++i) {
        c__[i] = sinf((float)(i % 50)) * 0.02f;
    }
}