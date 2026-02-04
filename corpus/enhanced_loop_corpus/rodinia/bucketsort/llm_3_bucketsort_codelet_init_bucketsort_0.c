#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with computed indices)
    int indices[1 << 10];
    for (int i = 0; i < (1 << 10); i++) {
        indices[i] = (i * 3) % (1 << 10); // Generate scrambled but deterministic indices
    }
    for (int i = 0; i < (1 << 10); i++) {
        h_offsets[indices[i]] = 0;
    }
}
