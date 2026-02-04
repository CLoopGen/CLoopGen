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
real *c__;
real *s;
singlecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__4;
singlecomplex q__1;
singlecomplex q__2;
singlecomplex q__3;
integer i__;
integer j;
singlecomplex temp;
real ctemp;
real stemp;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB for complex array (each element is 8 bytes)
    const integer m_val = 1000;
    const integer n_val = 1000;

    m = (integer*)malloc(sizeof(integer));
    *m = m_val;
    a_dim1 = m_val;
    i__1 = n_val;

    a = (singlecomplex*)calloc(data_size, sizeof(singlecomplex));
    c__ = (real*)calloc(n_val, sizeof(real));
    s = (real*)calloc(n_val, sizeof(real));

    for (integer idx = 0; idx < n_val; ++idx) {
        c__[idx] = 1.0f;
        s[idx] = idx % 2 ? 0.0f : 0.707f;
    }

    for (integer i = 1; i <= m_val; ++i) {
        for (integer j = 1; j <= n_val; ++j) {
            integer idx = i + j * a_dim1;
            if (idx < data_size) {
                a[idx].r = (real)(i % 100) + 0.5f;
                a[idx].i = (real)(j % 100) - 0.5f;
            }
        }
    }

    i__ = 0;
    j = 0;
    ctemp = 0.0f;
    stemp = 0.0f;
    temp.r = 0.0f;
    temp.i = 0.0f;
    q__1.r = 0.0f; q__1.i = 0.0f;
    q__2.r = 0.0f; q__2.i = 0.0f;
    q__3.r = 0.0f; q__3.i = 0.0f;
}