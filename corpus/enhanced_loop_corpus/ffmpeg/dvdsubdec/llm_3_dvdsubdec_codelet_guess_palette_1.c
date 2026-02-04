#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *rgba_palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with fixed offsets)
    int indices[4] = {3, 1, 2, 0}; // Arbitrary reordering of indices
    for (i = 0; i < 4; i++) {
        rgba_palette[indices[i]] = 0;
    }
}
