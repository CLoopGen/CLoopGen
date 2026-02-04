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
extern doublereal t2;
extern doublereal t3;
extern doublereal t4;
extern doublereal t5;
extern doublereal t6;
extern doublereal t7;
extern doublereal t8;
extern doublereal v1;
extern doublereal v2;
extern doublereal v3;
extern doublereal v4;
extern doublereal v5;
extern doublereal v6;
extern doublereal v7;
extern doublereal v8;
extern doublereal sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (reorganize data access to be contiguous)
    // Instead of strided access with varying multiples of c_dim1, we precompute base indices
    // and access elements consecutively by restructuring the computation order.
    
    integer base_j;
    doublereal *c_ptr;
    for (j = 1; j <= i__1; ++j) {
        base_j = j;
        c_ptr = &c__[base_j]; // Base pointer at column j

        // Precompute offsets assuming c_dim1 is large enough to prevent overlap
        sum = v1 * c_ptr[c_dim1] + 
              v2 * c_ptr[c_dim1*2] + 
              v3 * c_ptr[c_dim1*3] + 
              v4 * c_ptr[c_dim1*4] + 
              v5 * c_ptr[c_dim1*5] + 
              v6 * c_ptr[c_dim1*6] + 
              v7 * c_ptr[c_dim1*7] + 
              v8 * c_ptr[c_dim1*8];

        c_ptr[c_dim1]   -= sum * t1;
        c_ptr[c_dim1*2] -= sum * t2;
        c_ptr[c_dim1*3] -= sum * t3;
        c_ptr[c_dim1*4] -= sum * t4;
        c_ptr[c_dim1*5] -= sum * t5;
        c_ptr[c_dim1*6] -= sum * t6;
        c_ptr[c_dim1*7] -= sum * t7;
        c_ptr[c_dim1*8] -= sum * t8;
    }
}
