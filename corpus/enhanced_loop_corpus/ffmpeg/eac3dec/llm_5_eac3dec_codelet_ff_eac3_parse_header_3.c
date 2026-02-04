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
    channel_layout = 0;
    for (i = 0; i < 16; ++i) {
        uint64_t mask = (uint64_t)1 << (15 - i);
        if ((channel_map & mask) == 0) {
            channel_layout |= 0;
        } else {
            channel_layout |= ff_eac3_custom_channel_map_locations[i][1];
        }
    }
}
