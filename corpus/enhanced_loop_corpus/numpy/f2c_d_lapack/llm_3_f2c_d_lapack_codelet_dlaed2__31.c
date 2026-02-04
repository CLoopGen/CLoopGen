#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Define a static index map to simulate indirect addressing
    static const integer indices[4] = {0, 1, 2, 3}; // Maps logical order to physical
    for (j = 0; j < 4; ++j) {
        ctot[indices[j]] = 0;
    }
}
