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
for (i = 0; i < 4; i++) {  // Decreased effective work per iteration but increased stride logic
    int base = i * 4;
    for (int j = 0; j < 4; j++) {
        int idx = base + j;
        if (idx < 16 && (channel_map & (1 << (16 - idx - 1))))
            channel_layout |= ff_eac3_custom_channel_map_locations[idx][1];
    }
}
}
