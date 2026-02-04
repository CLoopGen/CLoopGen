#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint64_t ff_eac3_custom_channel_map_locations[16][2];
extern int i;
extern int64_t channel_layout;
extern int channel_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via lookup table to simulate indirect array indexing
    const int lookup[16] = {0, 2, 4, 6, 8, 10, 12, 14, 1, 3, 5, 7, 9, 11, 13, 15}; // Interleaved even-odd order
    for (i = 0; i < 16; i++) {
        int idx = lookup[i];
        if (channel_map & (1 << (16 - idx - 1)))
            channel_layout |= ff_eac3_custom_channel_map_locations[idx][1];
    }
}
