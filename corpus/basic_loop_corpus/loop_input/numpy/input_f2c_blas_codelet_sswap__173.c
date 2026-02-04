#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *sx;
real *sy;
integer i__1;
integer i__;
real stemp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 million elements ~ 256MB for two arrays of floats
    sx = (real*)calloc(data_size, sizeof(real));
    sy = (real*)calloc(data_size, sizeof(real));
    
    if (!sx || !sy) {
        exit(1);
    }
    
    // Initialize array contents
    for (size_t idx = 0; idx < data_size; ++idx) {
        sx[idx] = (real)(idx + 1.5);
        sy[idx] = (real)(idx + 2.5);
    }
    
    // Set loop bounds to iterate over all elements
    i__1 = data_size - 1; // so that i__ goes from 1 to i__1 inclusive
    i__ = 1;
    stemp = 0.0f;
}