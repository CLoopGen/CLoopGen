#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *levels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[15];
    for (int i = 0; i < 15; i++) {
        indices[i] = i; // Populate index map (could be randomized or reordered in real use)
    }
    for (int i = 0; i < 15; i++) {
        levels[indices[i]] = -100.;
    }
}
