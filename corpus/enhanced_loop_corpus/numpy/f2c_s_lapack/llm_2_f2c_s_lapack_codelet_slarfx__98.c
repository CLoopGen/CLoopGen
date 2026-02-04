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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the indexing logic
    // Assuming column-major layout, we modify access to be more cache-friendly
    // by traversing consecutive elements in memory (if c_dim1 is large, this helps)
    real *base = &c__[c_dim1 + 1]; // point to c[1][1]
    for (j = 0; j < i__1; ++j) {
        base[j * c_dim1] = t1 * base[j * c_dim1];
    }
}
