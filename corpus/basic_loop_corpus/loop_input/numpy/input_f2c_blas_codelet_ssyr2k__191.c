#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *k;
real *alpha;
real *a;
real *b;
real *beta;
real *c__;
integer a_dim1;
integer b_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
real temp1;
real temp2;

static real alpha_val = 1.5f;
static real beta_val = 1.0f;

static integer k_val;
static integer dim_size;

#define ALIGN_TO_64(x) (((x) + 63) & ~63)

void init_vars() {
    dim_size = 1024;  
    k_val = 256;

    i__1 = dim_size;
    a_dim1 = k_val;
    b_dim1 = k_val;
    c_dim1 = dim_size;

    alpha = &alpha_val;
    beta = &beta_val;
    k = &k_val;

    size_t a_size = (size_t)dim_size * k_val * sizeof(real);
    size_t b_size = (size_t)dim_size * k_val * sizeof(real);
    size_t c_size = (size_t)dim_size * dim_size * sizeof(real);

    a = (real*)aligned_alloc(64, a_size);
    b = (real*)aligned_alloc(64, b_size);
    c__ = (real*)aligned_alloc(64, c_size);

    for (size_t i = 0; i < dim_size * k_val; ++i) {
        a[i] = (real)(i % 128) / 128.0f;
        b[i] = (real)((i + 17) % 97) / 97.0f;
    }

    for (size_t i = 0; i < dim_size * dim_size; ++i) {
        c__[i] = (real)(i % 256) / 256.0f;
    }
}