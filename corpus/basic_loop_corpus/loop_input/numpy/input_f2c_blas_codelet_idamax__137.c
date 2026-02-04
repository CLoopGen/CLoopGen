#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef double doublereal;
typedef int integer;

doublereal *dx;
integer *incx;
integer ret_val;
integer i__1;
doublereal d__1;
integer i__;
integer ix;
doublereal dmax__;

void init_vars() {
    // Allocate large enough array to make loop take ~0.01 seconds
    // Assume typical modern CPU can do ~1e9 iterations/sec -> aim for ~1e7 iterations
    // Use 8MB of doubles: 1M elements * 8 bytes = 8MB
    const int array_size = 1000000;
    dx = (doublereal*)aligned_alloc(32, array_size * sizeof(doublereal));
    
    // Initialize data with non-trivial values to ensure meaningful comparisons
    for (int j = 0; j < array_size; ++j) {
        dx[j] = sin(j * 0.001) * 100.0;  // oscillating values between -100 and 100
    }
    
    // Set incx to a small positive value (common case is 1)
    incx = (integer*)malloc(sizeof(integer));
    *incx = 1;
    
    // Ensure loop runs for approximately 10 million iterations
    // But don't exceed array bounds: need i__1 <= array_size
    // Start at index 2, increment ix by incx each time
    // Max safe i__1: such that ix + (i__1 - 2)*(*incx) < array_size
    // Initial ix starts at some offset, say 100
    ix = 100;
    i__1 = 100000;  // 100k iterations should be sufficient for timing
    
    // Initialize dmax__ to a small value to allow updates
    dmax__ = 0.0;
    
    // Initialize ret_val to 1 (common initial value)
    ret_val = 1;
    
    // Initialize d__1 to zero
    d__1 = 0.0;
    
    // Ensure we won't go out of bounds during loop execution
    if (ix + (i__1 - 2) * (*incx) >= array_size) {
        i__1 = 2 + (array_size - ix - 1) / (*incx);
    }
}