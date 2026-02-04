#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *vt2;
extern integer vt2_dim1;
extern integer i__1;
extern integer i__;
extern integer nlp2;
extern integer ktemp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified memory access
    // Loop runs over a larger effective range by iterating per element in a flattened segment
    // Introduces redundant but simpler accesses to increase memory traffic relative to computation
    integer base_start = nlp2 * vt2_dim1;
    integer base_end = i__1 * vt2_dim1;
    for (integer j = base_start; j <= base_end; ++j) {
        vt2[ktemp + j] = vt2[j + 1]; // Strided write with uniform increment
    }
}
