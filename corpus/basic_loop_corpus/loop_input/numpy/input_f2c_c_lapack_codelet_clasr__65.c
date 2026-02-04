#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer *m;
integer *n;
real *c__;
real *s;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__;
integer j;
singlecomplex temp;
real ctemp;
real stemp;

static integer m_val = 512;
static integer n_val = 512;

void init_vars() {
    m = &m_val;
    n = &n_val;
    a_dim1 = 512;

    c__ = (real*)calloc(*m, sizeof(real));
    s = (real*)calloc(*m, sizeof(real));
    a = (singlecomplex*)calloc((a_dim1 + 1) * (*n + 1), sizeof(singlecomplex));

    if (!c__ || !s || !a) {
        exit(1);
    }

    for (integer idx = 0; idx < *m; ++idx) {
        c__[idx] = 1.0f;
        s[idx] = 0.0f;
    }
    c__[0] = 0.8f;
    s[0] = 0.6f;

    for (integer i = 1; i <= *m; ++i) {
        for (integer j = 1; j <= *n; ++j) {
            integer idx = j + i * a_dim1;
            a[idx].r = (real)(i % 17) * 0.5f;
            a[idx].i = (real)(j % 13) * 0.25f;
        }
    }
}