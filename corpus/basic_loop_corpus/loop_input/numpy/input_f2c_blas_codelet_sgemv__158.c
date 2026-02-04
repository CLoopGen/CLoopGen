#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float real;
typedef int integer;

real *y;
integer *incy;
integer i__1;
integer i__;
integer iy;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million elements for ~256MB of data (float is 4 bytes)
    
    y = (real*)aligned_alloc(32, data_size * sizeof(real));
    if (!y) exit(1);
    
    for (size_t i = 0; i < data_size; ++i) {
        y[i] = 1.0F;
    }

    incy = (integer*)aligned_alloc(32, sizeof(integer));
    if (!incy) exit(1);
    *incy = 1;

    i__1 = (integer)(data_size - 1); 
    i__ = 1;
    iy = 0;
}