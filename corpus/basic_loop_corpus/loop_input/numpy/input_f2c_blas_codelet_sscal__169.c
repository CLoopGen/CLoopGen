#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef float real;
typedef int integer;

real *sa;
real *sx;
integer i__1;
integer i__2;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for sx array, ensures ~0.01s runtime
    
    // Allocate sx array
    sx = (real*)aligned_alloc(32, data_size * sizeof(real));
    
    // Allocate sa as a single float
    sa = (real*)aligned_alloc(32, sizeof(real));
    
    // Initialize sa value
    *sa = 1.5f;
    
    // Initialize sx with some values
    for (size_t idx = 0; idx < data_size; ++idx) {
        sx[idx] = (real)(idx % 1000) / 100.0f;
    }
    
    // Set loop bounds: i__ from 1 to data_size-1, step by 1
    i__1 = (integer)(data_size - 1);
    i__2 = 1;
    i__ = 1; // initial value for the loop index
}