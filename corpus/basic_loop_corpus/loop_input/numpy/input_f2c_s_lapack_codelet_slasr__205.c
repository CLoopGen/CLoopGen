#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

integer *m;
integer *n;
real *c__;
real *s;
real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;
real temp;
real ctemp;
real stemp;

static real a_data[200000];
static integer m_data = 100;
static integer n_data = 50;
static real c_data[100];
static real s_data[100];

void init_vars() {
    m = &m_data;
    n = &n_data;
    c__ = c_data;
    s = s_data;
    a = a_data;
    a_dim1 = 2000;
    i__1 = 50;

    for (int idx = 0; idx < 100; ++idx) {
        c__[idx] = (idx % 7 != 0) ? 1.0f : 0.8f;
        s[idx] = (idx % 7 != 0) ? 0.0f : 0.6f;
    }

    const int total_size = (*m) * (a_dim1);
    for (int idx = 0; idx < total_size; ++idx) {
        a[idx] = (real)(idx % 1000) / 100.0f;
    }

    i__ = 0;
    j = 0;
    temp = 0.0f;
    ctemp = 0.0f;
    stemp = 0.0f;
}