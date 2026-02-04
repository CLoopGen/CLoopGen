#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float real;
typedef int integer;
typedef double doublereal;

real *sx;
integer ret_val;
integer i__1;
real r__1;
integer i__;
real smax;

void init_vars() {
    // Set array size to achieve approximately 0.01 seconds runtime
    // For typical modern CPU, 64M elements should be sufficient for this loop
    const size_t array_size = 67108864; // 64 * 2^20 ~ 67M elements
    
    // Allocate sx array
    sx = (real*)aligned_alloc(32, array_size * sizeof(real));
    
    // Initialize array with random-like data to ensure realistic branch behavior
    for (size_t idx = 0; idx < array_size; ++idx) {
        sx[idx] = (real)(rand() % 10000 - 5000) * 0.01f;
    }
    
    // Initialize loop bounds to stay within allocated memory
    i__1 = (integer)(array_size - 1);  // so sx[i__] access is valid for i__ from 2 to i__1
    i__ = 2;
    
    // Initialize smax to a small value to allow updates
    smax = 0.0f;
    
    // Initialize other variables
    ret_val = 1;
    r__1 = 0.0f;
}