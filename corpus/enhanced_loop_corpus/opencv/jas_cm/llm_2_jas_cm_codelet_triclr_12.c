#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double jas_cmreal_t;

extern int i;
extern jas_cmreal_t mat[3][4];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access by unrolling and accessing every element with a stride pattern
    // Although the original loop only writes to mat[i][3], we simulate a strided read-like behavior in logic
    // by processing elements in a non-sequential column order (still writing only to [i][3]).
    for (i = 0; i < 3; ++i) {
        // Accessing columns in reverse order just before assignment to introduce access pattern variation
        volatile jas_cmreal_t temp = mat[i][2]; temp += mat[i][1]; temp += mat[i][0]; // dummy read with stride
        mat[i][3] = 0.;
    }
}
