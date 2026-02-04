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
singlecomplex a_storage[1024 * 513]; // m x (n+1) to cover index up to *n
integer a_dim1_storage = 1024;

// Pointers to data
integer *m = &m_storage;
integer *n = &n_storage;
real *c__ = c_storage;
real *s = s_storage;
singlecomplex *a = a_storage;
integer a_dim1 = 1024;

// Loop indices and temporaries
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
    // Initialize c__ and s arrays
    for (int idx = 0; idx < *n; ++idx) {
        c__[idx] = cosf((float)(idx % 10 + 1) * 0.1f);
        s[idx] = sinf((float)(idx % 10 + 1) * 0.1f);
    }

    // Initialize a matrix with meaningful values
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j <= *n; ++j) {
            int idx = i + j * a_dim1;
            a[idx].r = (real)(i % 128) * 0.1f;
            a[idx].i = (real)(j % 128) * 0.1f;
        }
    }

    // Ensure at least some iterations enter the conditional branch
    c__[0] = 0.5f;
    s[0] = 0.5f;
}