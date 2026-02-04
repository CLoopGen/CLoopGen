#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

integer m_storage = 1024;
integer n_storage = 512;
real c_storage[512];
real s_storage[512];
singlecomplex a_storage[1024 * 513]; // m x (n+1) to cover index up to j+1
integer a_dim1_storage = 1024;

integer *m = &m_storage;
integer *n = &n_storage;
real *c__ = c_storage;
real *s = s_storage;
singlecomplex *a = a_storage;
integer a_dim1 = 1024;

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

void init_vars() {
    for (int idx = 0; idx < *n; ++idx) {
        c__[idx] = 0.5F + idx * 0.01F;
        s[idx] = 0.1F - idx * 0.001F;
    }

    int total_size = *m * (*n + 1);
    for (int idx = 0; idx < total_size; ++idx) {
        a[idx].r = (real)(idx % 128) * 0.1F;
        a[idx].i = (real)(idx % 64) * 0.2F;
    }
}