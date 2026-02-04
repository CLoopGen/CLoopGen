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
for (i = 0; i < 409 - 1; i += 2) {
    int j = i;
    if (ff_dv_vlc_run[j] >= 64)
        continue;
    if (dv_vlc_map[ff_dv_vlc_run[j]][ff_dv_vlc_level[j]].size != 0)
        continue;
    dv_vlc_map[ff_dv_vlc_run[j]][ff_dv_vlc_level[j]].vlc = ff_dv_vlc_bits[j] << (!!ff_dv_vlc_level[j]);
    dv_vlc_map[ff_dv_vlc_run[j]][ff_dv_vlc_level[j]].size = ff_dv_vlc_len[j] + (!!ff_dv_vlc_level[j]);

    if (i + 1 < 409 - 1) {
        j = i + 1;
        if (ff_dv_vlc_run[j] >= 64)
            continue;
        if (dv_vlc_map[ff_dv_vlc_run[j]][ff_dv_vlc_level[j]].size != 0)
            continue;
        dv_vlc_map[ff_dv_vlc_run[j]][ff_dv_vlc_level[j]].vlc = ff_dv_vlc_bits[j] << (!!ff_dv_vlc_level[j]);
        dv_vlc_map[ff_dv_vlc_run[j]][ff_dv_vlc_level[j]].size = ff_dv_vlc_len[j] + (!!ff_dv_vlc_level[j]);
    }
}
}
