#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern float highest;
extern float workT[32];
extern int found_indx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulating non-sequential access pattern)
    int index_map[32];
    for (int temp_i = 0; temp_i < 32; temp_i++) {
        index_map[temp_i] = (13 * temp_i + 7) % 32; // Simple pseudo-random permutation
    }
    highest = -__FLT_MAX__;
    found_indx = -1;
    for (i = 0; i < 32; i++) {
        int mapped_idx = index_map[i];
        if (workT[mapped_idx] > highest) {
            highest = workT[mapped_idx];
            found_indx = mapped_idx;
        }
    }
}
