#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with indirect read via offset array
    int offsets[63];
    for (int j = 0; j < 63; j++) {
        offsets[j] = j;  // Simulate indirect access pattern
    }
    for (i = 0; i < 63; i++) {
        int idx = offsets[i];  // Use indirect indexing (could be randomized or reordered in practice)
        filtered_top[idx] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
    }
}
