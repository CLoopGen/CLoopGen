#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    // Define a static index permutation to simulate indirect access pattern
    const integer indices[4] = {3, 1, 0, 2}; // Custom access order
    for (j = 0; j < 4; ++j) {
        ctot[indices[j]] = 0;
    }
}
