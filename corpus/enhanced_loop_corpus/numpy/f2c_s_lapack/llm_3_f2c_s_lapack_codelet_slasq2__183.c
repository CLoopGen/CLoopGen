#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *z__;
extern integer i__1;
extern integer i0;
extern integer i4;
extern integer ipn4;
extern real temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride via indirect indexing
    // Simulate a different memory access pattern using an index array (indirect addressing)
    // We create a local array of indices to simulate non-consecutive, irregular access pattern
    // while maintaining functional equivalence.

    integer indices[4];
    for (i4 = i0 << 2; i4 <= i__1; i4 += 4) {
        // Populate index map for current iteration (indirect access)
        indices[0] = i4 - 3;
        indices[1] = ipn4 - i4 - 3;
        indices[2] = i4 - 1;
        indices[3] = ipn4 - i4 - 5;

        // Perform swap using indirect addressing
        temp = z__[indices[0]];
        z__[indices[0]] = z__[indices[1]];
        z__[indices[1]] = temp;

        temp = z__[indices[2]];
        z__[indices[2]] = z__[indices[3]];
        z__[indices[3]] = temp;
    }
}
