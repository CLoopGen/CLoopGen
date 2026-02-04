#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer m_data = 1024;
integer n_data = 512;
doublereal c_data[1024];
doublereal s_data[1024];
doublecomplex a_data[1024 * 1024];

integer a_dim1 = 1024;
integer i__1;
integer i__2;
integer i__3;
doublecomplex z__1;
doublecomplex z__2;
doublecomplex z__3;
integer i__;
integer j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

integer *m = &m_data;
integer *n = &n_data;
doublereal *c__ = c_data;
doublereal *s = s_data;
doublecomplex *a = a_data;

void init_vars() {
    for (int idx = 0; idx < 1024; ++idx) {
        c__[idx] = (idx % 7 == 0) ? 1.0 : 0.8 + (idx % 3) * 0.1;
        s[idx] = (idx % 5 == 0) ? 0.0 : 0.1 + (idx % 4) * 0.2;
    }

    for (int i = 0; i < 1024 * 1024; ++i) {
        a[i].r = (doublereal)(i % 127) * 0.07;
        a[i].i = (doublereal)(i % 89) * 0.09;
    }
}