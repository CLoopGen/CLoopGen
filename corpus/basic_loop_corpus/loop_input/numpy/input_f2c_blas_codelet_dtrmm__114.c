#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;
typedef int logical;

integer *m;
doublereal *alpha;
doublereal *a;
doublereal *b;
integer a_dim1;
integer b_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
integer k;
doublereal temp;
logical nounit;

static integer m_val;
static doublereal alpha_val;
static doublereal *a_data;
static doublereal *b_data;

void init_vars() {
    m_val = 500;
    m = &m_val;

    alpha_val = 1.5;
    alpha = &alpha_val;

    a_dim1 = m_val;
    b_dim1 = m_val;
    i__1 = m_val;

    nounit = 1;

    a_data = (doublereal*)calloc(m_val * m_val, sizeof(doublereal));
    b_data = (doublereal*)calloc(m_val * m_val, sizeof(doublereal));

    a = a_data;
    b = b_data;

    for (integer idx = 0; idx < m_val * m_val; ++idx) {
        a_data[idx] = 1.0 + (idx % 7) * 0.1;
        b_data[idx] = 2.0 + (idx % 5) * 0.2;
    }

    i__ = 0;
    j = 0;
    k = 0;
    i__2 = 0;
    temp = 0.0;
}