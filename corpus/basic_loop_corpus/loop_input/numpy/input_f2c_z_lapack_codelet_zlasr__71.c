#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer m_storage = 1024;
integer n_storage = 512;
doublereal c_storage[512];
doublereal s_storage[512];
doublecomplex a_storage[1024 * 513]; // m x (n+1), using 1-based indexing

integer *m = &m_storage;
integer *n = &n_storage;
doublereal *c__ = c_storage;
doublereal *s = s_storage;
doublecomplex *a = a_storage;
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

void init_vars() {
    for (int idx = 0; idx < 512; ++idx) {
        c__[idx] = 0.5 + idx * 0.01;
        s[idx] = idx % 2 ? 0.1 : -0.1;
    }
    
    for (int idx = 0; idx < 1024 * 513; ++idx) {
        a[idx].r = (doublereal)(rand() % 100) / 10.0;
        a[idx].i = (doublereal)(rand() % 100) / 10.0;
    }
}