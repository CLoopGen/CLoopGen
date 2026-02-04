#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
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
real temp;

static integer m_val = 512;
static integer k_val = 512;
static real alpha_val = 1.5f;
static real beta_val = 1.0f;

static integer i1_val = 512;
static integer i2_val;
static integer i3_val;

void init_vars() {
    m = &m_val;
    k = &k_val;
    alpha = &alpha_val;
    beta = &beta_val;
    a_dim1 = m_val;
    b_dim1 = k_val;
    c_dim1 = m_val;
    i__1 = i1_val;
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
    l = 0;
    temp = 0.0f;

    size_t a_size = (size_t)m_val * (size_t)k_val;
    size_t b_size = (size_t)k_val * (size_t)i1_val;
    size_t c_size = (size_t)m_val * (size_t)i1_val;

    a = (real*)calloc(a_size, sizeof(real));
    b = (real*)calloc(b_size, sizeof(real));
    c__ = (real*)calloc(c_size, sizeof(real));

    if (!a || !b || !c__) {
        exit(1);
    }

    for (size_t i = 0; i < a_size; ++i) {
        a[i] = (real)(i % 256) * 0.1f;
    }
    for (size_t i = 0; i < b_size; ++i) {
        b[i] = (real)((i % 128) < 10 ? 1.0f : 0.0f);
    }
    for (size_t i = 0; i < c_size; ++i) {
        c__[i] = (real)(i % 256) * 0.05f;
    }
}