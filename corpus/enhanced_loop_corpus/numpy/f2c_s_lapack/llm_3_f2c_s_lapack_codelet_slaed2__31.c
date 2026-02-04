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
    integer indices[4] = {3, 1, 2, 0}; // Custom access order: 4th, 2nd, 3rd, 1st elements
    for (j = 0; j < 4; ++j) {
        ctot[indices[j]] = 0;
    }
}
