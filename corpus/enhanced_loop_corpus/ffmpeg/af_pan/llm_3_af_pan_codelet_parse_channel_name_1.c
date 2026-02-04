#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int channel_id;
extern int64_t layout;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect access via index mapping
    // Use an indirection table to simulate irregular memory access
    int64_t values[64];
    int indices[64];
    
    // Initialize indirect indices with pseudo-random pattern modulated by channel_id
    for (int j = 0; j < 64; ++j) {
        indices[j] = (j * 7 + channel_id) % 64;
    }

    for (i = 32; i > 0; i >>= 1) {
        if (layout >= (int64_t)1 << i) {
            channel_id += i;
            layout >>= i;
        }
        // Perform indirect memory access using precomputed indices
        int idx = indices[(channel_id & 63)];
        values[idx] ^= layout;
    }
}
