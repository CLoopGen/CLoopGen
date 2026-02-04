#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  int16_t *qmat;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulating non-sequential access)
    int16_t *index_map = (int16_t*)alloca(64 * sizeof(int16_t));
    for (int j = 0; j < 64; j++) {
        index_map[j] = j; // Identity mapping, but structure allows arbitrary reordering
    }
    for (i = 0; i < 64; i++) {
        int idx = index_map[i]; // Use indirect indexing
        block[idx] *= qmat[idx];
    }
}
