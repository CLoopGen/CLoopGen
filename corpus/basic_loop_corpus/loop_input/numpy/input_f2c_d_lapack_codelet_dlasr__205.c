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
integer i__2;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

static doublereal a_data[2000 * 100];
static integer m_data = 2000;
static integer n_data = 50;
static doublereal c_data[100];
static doublereal s_data[100];

void init_vars() {
    m = &m_data;
    n = &n_data;
    a = &a_data[0];
    c__ = &c_data[0];
    s = &s_data[0];
    a_dim1 = 2000;
    i__1 = 99;

    for (int j = 0; j <= i__1; ++j) {
        c__[j] = 0.8;
        s[j] = 0.6;
    }
    c__[50] = 1.0;
    s[50] = 0.0;

    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j < 100; ++j) {
            a[i + j * a_dim1] = (doublereal)(i % 100 + j);
        }
    }
}