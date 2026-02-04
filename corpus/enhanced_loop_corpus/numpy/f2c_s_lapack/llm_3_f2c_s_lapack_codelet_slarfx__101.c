#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern real t1;
extern real t2;
extern real t3;
extern real t4;
extern real v1;
extern real v2;
extern real v3;
extern real v4;
extern real sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access array elements with a fixed stride across iterations, simulating column-major traversal
    // Here we change the effective access pattern by looping over vector components first
    integer idx;
    for (j = 1; j <= i__1; ++j) {
        sum = 0.0f;
        // Strided accumulation: simulate unrolled dot product with stride = c_dim1
        for (integer k = 0; k < 4; ++k) {
            idx = j * c_dim1 + (k + 1);
            real coeff = (k == 0) ? v1 : (k == 1) ? v2 : (k == 2) ? v3 : v4;
            sum += coeff * c__[idx];
        }
        // Apply updates with corresponding t values using same strided index
        c__[j * c_dim1 + 1] -= sum * t1;
        c__[j * c_dim1 + 2] -= sum * t2;
        c__[j * c_dim1 + 3] -= sum * t3;
        c__[j * c_dim1 + 4] -= sum * t4;
    }
}
