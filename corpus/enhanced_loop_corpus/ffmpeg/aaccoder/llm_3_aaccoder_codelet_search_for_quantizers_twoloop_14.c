#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int maxsf[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[sizeof(maxsf) / sizeof(maxsf[0])];
    for (i = 0; i < sizeof(maxsf) / sizeof(maxsf[0]); ++i) {
        indices[i] = i; // Populate index map
    }
    for (i = 0; i < sizeof(maxsf) / sizeof(maxsf[0]); ++i) {
        maxsf[indices[i]] = 255; // Use indirect addressing
    }
}
