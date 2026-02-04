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

static real a_data[1024 * 256];
static real b_data[1024 * 256];
static integer m_value;
static real alpha_value;

void init_vars() {
    m_value = 512;
    m = &m_value;
    alpha_value = 1.5f;
    alpha = &alpha_value;
    a = a_data;
    b = b_data;
    a_dim1 = m_value;
    b_dim1 = m_value;
    i__1 = m_value;
    nounit = 1;

    for (int idx = 0; idx < m_value * m_value; ++idx) {
        a_data[idx] = (real)(idx % 128 + 1);
        b_data[idx] = (real)(idx % 64 + 1);
    }
}