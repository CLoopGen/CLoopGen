#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef int integer;

extern doublereal *c__;
extern integer c_dim1;
extern integer i__1;
extern integer j;
extern doublereal t1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Linearized) Memory Access Pattern
    // Reinterpret the 2D array access as a linear sequence starting at offset c_dim1.
    // This ensures fully consecutive memory access, improving cache locality.
    integer base_index = c_dim1 + 1;
    for (integer k = 0; k < i__1; ++k) {
        c__[base_index + k] = t1 * c__[base_index + k];
    }
}
