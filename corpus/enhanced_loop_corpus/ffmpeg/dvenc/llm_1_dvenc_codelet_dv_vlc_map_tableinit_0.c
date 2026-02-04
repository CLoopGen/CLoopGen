#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct dv_vlc_pair {
    uint32_t vlc;
    uint32_t size;
};


extern const uint16_t ff_dv_vlc_bits[409];
extern const uint8_t ff_dv_vlc_len[409];
extern const uint8_t ff_dv_vlc_run[409];
extern const uint8_t ff_dv_vlc_level[409];
extern struct dv_vlc_pair dv_vlc_map[64][512];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Outer loop split into two consecutive loops to reduce effective nesting (flattened structure with segmentation)
    int mid = (409 - 1) / 2;
    for (i = 0; i < mid; i++) {
        if (ff_dv_vlc_run[i] >= 64)
            continue;
        if (dv_vlc_map[ff_dv_vlc_run[i]][ff_dv_vlc_level[i]].size != 0)
            continue;
        dv_vlc_map[ff_dv_vlc_run[i]][ff_dv_vlc_level[i]].vlc = ff_dv_vlc_bits[i] << (!!ff_dv_vlc_level[i]);
        dv_vlc_map[ff_dv_vlc_run[i]][ff_dv_vlc_level[i]].size = ff_dv_vlc_len[i] + (!!ff_dv_vlc_level[i]);
    }
    for (i = mid; i < 409 - 1; i++) {
        if (ff_dv_vlc_run[i] >= 64)
            continue;
        if (dv_vlc_map[ff_dv_vlc_run[i]][ff_dv_vlc_level[i]].size != 0)
            continue;
        dv_vlc_map[ff_dv_vlc_run[i]][ff_dv_vlc_level[i]].vlc = ff_dv_vlc_bits[i] << (!!ff_dv_vlc_level[i]);
        dv_vlc_map[ff_dv_vlc_run[i]][ff_dv_vlc_level[i]].size = ff_dv_vlc_len[i] + (!!ff_dv_vlc_level[i]);
    }
}
