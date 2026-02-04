#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

integer m_storage = 1000;
integer n_storage = 500;
doublereal c_storage[500];
doublereal s_storage[500];
doublereal a_storage[1000 * 501]; // m x (n+1) to allow indexing up to *n
integer a_dim1_storage = 1000;

integer *m = &m_storage;
integer *n = &n_storage;
doublereal *c__ = c_storage;
doublereal *s = s_storage;
doublereal *a = a_storage;
integer a_dim1 = 1000;

integer i__1;
integer i__;
integer j;
doublereal temp;
doublereal ctemp;
doublereal stemp;

void init_vars() {
    // Initialize c and s arrays
    for (int idx = 0; idx < *n; ++idx) {
        c__[idx] = 0.7 + (idx % 3) * 0.1;  // Values near 1.0 but not exactly 1.0 or 0.0
        s[idx] = (idx % 2) ? 0.3 : -0.4;   // Non-zero values to ensure the condition triggers
    }
    
    // Fix last element to possibly skip inner loop for some iterations
    c__[*n - 1] = 1.0;
    s[*n - 1] = 0.0;
    
    // Initialize matrix a with non-zero values
    for (int i = 0; i < *m; ++i) {
        for (int j = 0; j <= *n; ++j) {
            a[i + j * a_dim1] = (doublereal)(i + j * 37) / 100.0; // Arbitrary pattern
        }
    }
}