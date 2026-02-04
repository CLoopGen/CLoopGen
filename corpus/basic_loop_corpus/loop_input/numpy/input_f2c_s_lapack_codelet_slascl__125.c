#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;
integer k1;
integer k3;
real mul;

void init_vars() {
    // Set matrix dimensions and loop bounds
    a_dim1 = 2048;  // leading dimension
    k1 = 2000;
    k3 = 1900;
    i__1 = 1000;  // j loop bound
    mul = 1.5f;

    // Ensure valid loop bounds: j from 1 to i__1, i__ from max(k1-j,1) to k3
    // We must ensure that max(k1-j,1) <= k3 for some iterations to be valid
    // With k1=2000, i__1=1000, then k1-j ranges from 1999 down to 1000
    // So we require k3 >= 1000 to have valid access. Adjust k3 accordingly.
    k3 = 2000;

    // Allocate enough memory: indices go up to i__ + j*a_dim1
    // Max i__ is k3 = 2000, max j is i__1 = 1000
    // So max index is 2000 + 1000 * a_dim1 = 2000 + 1000*2048 = ~2,050,000 elements
    size_t total_elements = 2050000;
    a = (real*)calloc(total_elements, sizeof(real));
    if (!a) {
        exit(1);
    }

    // Initialize accessed portion of the array to non-zero for visibility
    for (size_t idx = 0; idx < total_elements; ++idx) {
        a[idx] = (real)(idx % 100) * 0.5f;
    }
}