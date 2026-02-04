#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer *m;
integer *n;
doublereal *c__;
doublereal *s;
doublereal *a;
integer a_dim1;
integer i__1;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

static integer m_val = 500;
static integer n_val = 1000;
static integer a_size;

void init_vars() {
    m = &m_val;
    n = &n_val;
    a_dim1 = m_val;
    a_size = (m_val + 1) * (n_val + 1);
    
    a = (doublereal*)calloc(a_size, sizeof(doublereal));
    c__ = (doublereal*)calloc(m_val + 1, sizeof(doublereal));
    s = (doublereal*)calloc(m_val + 1, sizeof(doublereal));

    if (!a || !c__ || !s) {
        exit(1);
    }

    for (integer idx = 0; idx <= m_val; ++idx) {
        a[idx] = idx * 0.1;
        for (integer jdx = 1; jdx <= n_val; ++jdx) {
            a[idx + jdx * a_dim1] = sin(idx * 3.14159 / 180.0) * cos(jdx * 0.1);
        }
    }

    for (integer j = 1; j < m_val; ++j) {
        double angle = j * 0.01;
        c__[j] = cos(angle);
        s[j] = sin(angle);
    }

    c__[m_val] = 1.0;
    s[m_val] = 0.0;

    i__ = 0;
    j = 0;
    temp = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
    i__1 = n_val;
}