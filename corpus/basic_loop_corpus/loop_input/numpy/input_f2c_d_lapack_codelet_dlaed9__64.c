#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *q;
doublereal *dlamda;
doublereal *w;
integer q_dim1;
integer i__1;
integer i__2;
integer i__;
integer j;

void init_vars() {
    const int n = 2048;  // Size to achieve ~0.01s runtime on modern CPU
    
    i__1 = n;
    q_dim1 = n;
    k = (integer*)malloc(sizeof(integer));
    *k = n;

    size_t total_q_size = (n + 1) * (n + 1);  // 1-based indexing, up to [n][n]
    q = (doublereal*)calloc(total_q_size, sizeof(doublereal));
    
    dlamda = (doublereal*)calloc(n + 1, sizeof(doublereal));
    w = (doublereal*)calloc(n + 1, sizeof(doublereal));

    // Initialize dlamda with distinct values to avoid division by zero
    for (int idx = 1; idx <= n; ++idx) {
        dlamda[idx] = (doublereal)(idx * 2);
    }

    // Initialize w with ones so multiplication has effect
    for (int idx = 1; idx <= n; ++idx) {
        w[idx] = 1.0;
    }

    // Initialize q with non-zero values
    for (int jj = 1; jj <= n; ++jj) {
        for (int ii = 1; ii <= n; ++ii) {
            q[ii + jj * q_dim1] = (doublereal)(ii * jj % 17) / 16.0 + 1.0;
        }
    }
}