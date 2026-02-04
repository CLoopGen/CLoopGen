#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *scale;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index mapping array
    // Simulates irregular access pattern using a precomputed index map
    integer *indices = (integer*)malloc(sizeof(integer) * (i__1 + 1));
    if (indices == NULL) return; // Handle allocation failure
    for (i__ = 1; i__ <= i__1; ++i__) {
        indices[i__] = i__; // Identity map (could be randomized or reordered in real use cases)
    }
    for (i__ = 1; i__ <= i__1; ++i__) {
        scale[indices[i__]] = 1.F;
    }
    free(indices);
}
