#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

static integer m_val;
static integer n_val;

void init_vars() {
    m_val = 500;
    n_val = 500;
    m = &m_val;
    n = &n_val;
    a_dim1 = m_val;

    c__ = (doublereal*)calloc(*m, sizeof(doublereal));
    s = (doublereal*)calloc(*m, sizeof(doublereal));
    a = (doublereal*)calloc((size_t)(*m + 1) * (size_t)(*n + 1), sizeof(doublereal));

    for (integer idx = 0; idx < *m; ++idx) {
        c__[idx] = 1.0;
        s[idx] = 0.0;
    }
    for (integer idx = 0; idx < *m; ++idx) {
        if (idx % 2 == 0) {
            c__[idx] = 0.8;
            s[idx] = 0.6;
        }
    }

    for (integer i = 1; i <= *n; ++i) {
        for (integer j = 1; j <= *m; ++j) {
            a[j + i * a_dim1] = (doublereal)(j * i);
        }
    }
}