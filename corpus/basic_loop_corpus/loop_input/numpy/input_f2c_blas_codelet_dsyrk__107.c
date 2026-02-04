#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;
typedef double doublereal;

integer *k;
doublereal *alpha;
doublereal *a;
doublereal *beta;
doublereal *c__;
integer a_dim1;
integer c_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer l;
doublereal temp;

static integer k_storage;
static doublereal alpha_storage;
static doublereal beta_storage;
static doublereal *a_storage;
static doublereal *c_storage;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Empirical tuning: for typical modern CPU, use matrix sizes around 1000x1000
    i__1 = 1000;        // j loop bound (also max j)
    k_storage = 1000;   // k value (l loop bound)
    
    a_dim1 = 1000;      // leading dimension of a
    c_dim1 = 1000;      // leading dimension of c__

    alpha_storage = 1.5;
    beta_storage = 1.2;

    // Allocate arrays with proper sizes to avoid out-of-bounds access
    // a is indexed up to [j + l * a_dim1], with j <= i__1=1000, l <= k=1000
    // so maximum index is 1000 + 1000*1000 = 1001000
    a_storage = (doublereal*)calloc(1001001, sizeof(doublereal));
    if (!a_storage) exit(1);

    // c__ is indexed up to [i__ + j * c_dim1], i__<=j<=1000, so max index 1000 + 1000*1000 = 1001000
    c_storage = (doublereal*)calloc(1001001, sizeof(doublereal));
    if (!c_storage) exit(1);

    // Initialize a with non-zero values in lower triangular part to trigger computation
    for (int idx = 1; idx <= 1000; ++idx) {
        for (int idy = 1; idy <= 1000; ++idy) {
            a_storage[idy + idx * a_dim1] = (doublereal)(idx + idy * 0.1);
        }
    }

    // Initialize c__ with some base values
    for (int idx = 1; idx <= 1000; ++idx) {
        for (int idy = 1; idy <= idx; ++idy) {
            c_storage[idy + idx * c_dim1] = (doublereal)(idx * 2.0);
        }
    }

    // Point external pointers to storage
    k = &k_storage;
    alpha = &alpha_storage;
    a = a_storage;
    beta = &beta_storage;
    c__ = c_storage;

    // Set loop bounds used internally
    i__2 = 0;
    i__3 = 0;
    i__ = 0;
    j = 0;
    l = 0;
    temp = 0.0;
}