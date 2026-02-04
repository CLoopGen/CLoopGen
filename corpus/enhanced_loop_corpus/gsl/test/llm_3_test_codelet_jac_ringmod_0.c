#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from last to first element
    for (size_t j = 15 * 15 - 1; j != (size_t)-1; j--) {
        dfdy[j] = 0.;
    }
}
