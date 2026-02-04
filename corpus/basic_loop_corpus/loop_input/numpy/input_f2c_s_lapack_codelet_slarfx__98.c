#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *c__;
integer c_dim1;
integer i__1;
integer j;
real t1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data
    c_dim1 = 8192;
    i__1 = (data_size / sizeof(real)) / c_dim1;
    if (i__1 == 0) i__1 = 1;
    size_t total_elements = (i__1 + 1) * (c_dim1 + 1);
    
    c__ = (real*)calloc(total_elements, sizeof(real));
    if (!c__) exit(1);

    t1 = 1.5f;

    for (integer idx = 0; idx <= i__1; ++idx) {
        for (integer k = 0; k <= c_dim1; ++k) {
            c__[idx * c_dim1 + k] = (real)(idx + k);
        }
    }
}