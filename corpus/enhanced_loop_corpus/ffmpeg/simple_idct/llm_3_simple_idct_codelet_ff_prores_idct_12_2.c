#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    int16_t indices[64];
    for (int j = 0; j < 64; j++) {
        indices[j] = 63 - j;  // Reverse order access
    }
    for (i = 0; i < 64; i++) {
        int idx = indices[i];
        block[idx] *= qmat[idx];
    }
}
