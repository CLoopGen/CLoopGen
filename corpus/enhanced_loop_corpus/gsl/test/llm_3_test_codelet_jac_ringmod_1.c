#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dfdt[];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index mapping array
    size_t indices[15];
    for (size_t j = 0; j < 15; j++) {
        indices[j] = j; // Populate index map
    }
    for (size_t k = 0; k < 15; k++) {
        dfdt[indices[k]] = 0.;
    }
}
