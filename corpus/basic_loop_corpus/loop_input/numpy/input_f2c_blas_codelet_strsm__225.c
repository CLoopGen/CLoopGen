#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
integer i__3;
integer i__;
integer j;
integer k;
real temp;
logical nounit;

static real alpha_val = 1.0f;
static integer m_val = 1024;
static integer a_dim1_val = 1024;
static integer b_dim1_val = 1024;
static integer i__1_val = 512;
static logical nounit_val = 1;

static real *a_data;
static real *b_data;

void init_vars() {
    m = &m_val;
    alpha = &alpha_val;
    a_dim1 = a_dim1_val;
    b_dim1 = b_dim1_val;
    i__1 = i__1_val;
    nounit = nounit_val;
    temp = 1.0f;

    a_dim1_val = (a_dim1_val < i__1_val) ? i__1_val : a_dim1_val;
    b_dim1_val = (b_dim1_val < i__1_val) ? i__1_val : b_dim1_val;

    a_data = (real*)calloc(a_dim1_val * a_dim1_val, sizeof(real));
    b_data = (real*)calloc(m_val * b_dim1_val, sizeof(real));

    if (!a_data || !b_data) {
        exit(1);
    }

    for (int idx = 0; idx < a_dim1_val * a_dim1_val; ++idx) {
        a_data[idx] = (real)(1.0f + (idx % 7) * 0.1f);
    }
    for (int idx = 0; idx < m_val * b_dim1_val; ++idx) {
        b_data[idx] = (real)(2.0f + (idx % 5) * 0.2f);
    }

    a = a_data;
    b = b_data;
}