#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;
typedef int logical;

integer *m;
real *alpha;
real *a;
real *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

static real alpha_val = 1.5f;
static integer m_val = 800;
static integer a_dim1_val = 800;
static integer b_dim1_val = 800;
static integer i__1_val = 600;

void init_vars() {
    m = &m_val;
    alpha = &alpha_val;
    a_dim1 = a_dim1_val;
    b_dim1 = b_dim1_val;
    i__1 = i__1_val;
    nounit = 1;

    a = (real*)aligned_alloc(64, sizeof(real) * a_dim1 * (*m));
    b = (real*)aligned_alloc(64, sizeof(real) * b_dim1 * i__1_val);

    for (int idx = 0; idx < a_dim1 * (*m); ++idx) {
        a[idx] = (real)(drand48() * 2.0 - 1.0);
    }
    for (int idx = 0; idx < b_dim1 * i__1_val; ++idx) {
        b[idx] = (real)(drand48() > 0.8 ? drand48() * 2.0 - 1.0 : 0.0);
    }

    temp = 0.0f;
    i__2 = 0;
    i__ = 0;
    j = 0;
    k = 0;
}