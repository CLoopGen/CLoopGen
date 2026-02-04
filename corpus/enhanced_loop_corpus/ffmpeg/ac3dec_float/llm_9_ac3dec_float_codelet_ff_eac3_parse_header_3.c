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
    for (i = 15; i >= 0; i--) {
        uint64_t mask = (uint64_t)1 << (16 - i - 1);
        if (channel_map & mask) {
            int64_t loc = ff_eac3_custom_channel_map_locations[i][1];
            channel_layout = channel_layout | loc;
        }
    }
}
