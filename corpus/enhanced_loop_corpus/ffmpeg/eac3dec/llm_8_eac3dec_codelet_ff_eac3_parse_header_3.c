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
    int j;
    for (i = 0; i < 8; i += 2) {
        if (channel_map & (1 << (15 - i)))
            channel_layout |= ff_eac3_custom_channel_map_locations[i][1];
        j = i + 1;
        if (j < 16 && (channel_map & (1 << (15 - j))))
            channel_layout |= ff_eac3_custom_channel_map_locations[j][1];
    }
}
