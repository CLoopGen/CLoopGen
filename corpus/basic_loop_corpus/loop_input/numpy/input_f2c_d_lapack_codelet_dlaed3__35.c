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

static doublereal q_data[65536];
static doublereal dlamda_data[256];
static doublereal w_data[256];
static integer k_storage;

void init_vars() {
    const int n = 256;
    
    i__1 = n;
    q_dim1 = n;
    k_storage = n;
    k = &k_storage;
    
    q = q_data;
    dlamda = dlamda_data;
    w = w_data;
    
    for (int idx = 0; idx < n; ++idx) {
        dlamda[idx] = 1.0 + idx * 0.1;
        w[idx] = 1.0 + idx * 0.01;
        for (int jdx = 0; jdx < n; ++jdx) {
            q[idx + jdx * q_dim1] = (idx == jdx) ? 1.0 : 0.01 * ((idx + jdx) % 17 - 8);
        }
    }
}