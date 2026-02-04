#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

integer *m;
integer *n;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

static real *a_data = NULL;
static integer m_val, n_val;

void init_vars() {
    m_val = 2048;
    n_val = 512;

    m = &m_val;
    n = &n_val;

    a_dim1 = m_val;

    c__ = (real*)calloc(n_val, sizeof(real));
    s = (real*)calloc(n_val, sizeof(real));
    a_data = (real*)calloc(m_val * (n_val + 1), sizeof(real));
    a = a_data;

    for (integer idx = 0; idx < n_val; ++idx) {
        c__[idx] = 0.8f;
        s[idx] = 0.6f;
    }
    c__[n_val - 1] = 1.0f;
    s[n_val - 1] = 0.0f;

    for (integer i = 0; i < m_val; ++i) {
        for (integer j = 0; j <= n_val; ++j) {
            a[i + j * a_dim1] = (real)(i + j);
        }
    }

    i__1 = 0;
    i__ = 0;
    j = 0;
    temp = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
}