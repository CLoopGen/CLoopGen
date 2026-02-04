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
doublecomplex a_storage[1024 * 513]; // m x (n+1) to avoid out-of-bounds

integer a_dim1_storage = 1024;

integer i__1, i__2, i__3;
doublecomplex z__1, z__2, z__3;
integer i__, j;
doublecomplex temp;
doublereal ctemp;
doublereal stemp;

// Pointers to data
integer *m = &m_storage;
integer *n = &n_storage;
doublereal *c__ = c_storage;
doublereal *s = s_storage;
doublecomplex *a = a_storage;
integer a_dim1 = 1024;

void init_vars() {
    // Initialize c and s arrays
    for (int idx = 0; idx < *n; ++idx) {
        c__[idx] = cos((idx + 1) * 0.01);
        s[idx] = sin((idx + 1) * 0.01);
    }

    // Initialize a matrix with m rows and at least n+1 columns
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j <= *n; ++j) {
            int idx = i + j * a_dim1;
            a[idx].r = (doublereal)(i + j);
            a[idx].i = (doublereal)(i - j);
        }
    }

    // Ensure c[0] is not (1.0, 0.0) to trigger computation in first iterations
    c__[0] = 0.99;

    // Initialize temporaries to zero
    temp.r = 0.0; temp.i = 0.0;
    ctemp = 0.0;
    stemp = 0.0;
    z__1.r = 0.0; z__1.i = 0.0;
    z__2.r = 0.0; z__2.i = 0.0;
    z__3.r = 0.0; z__3.i = 0.0;
    i__1 = 0;
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
}