#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
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

static doublereal a_data[200000];
static integer m_data = 100;
static integer n_data = 2000;
static doublereal c_data[2000];
static doublereal s_data[2000];

void init_vars() {
    m = &m_data;
    n = &n_data;
    c__ = c_data;
    s = s_data;
    a = a_data;
    a_dim1 = m_data;

    for (int i = 0; i < *n; ++i) {
        c__[i] = cos(0.1 * (i + 1));
        s[i] = sin(0.1 * (i + 1));
    }

    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j < *n; ++j) {
            a[i + j * a_dim1] = (doublereal)(i * *n + j + 1);
        }
    }

    i__1 = 0;
    i__ = 0;
    j = 0;
    temp = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
}