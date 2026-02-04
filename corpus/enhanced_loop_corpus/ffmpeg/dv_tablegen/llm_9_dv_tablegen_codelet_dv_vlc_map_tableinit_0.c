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
for (i = 1; i < 409; i++) {
    uint8_t run = ff_dv_vlc_run[i];
    uint8_t level = ff_dv_vlc_level[i];
    uint32_t bits = ff_dv_vlc_bits[i];
    uint8_t len = ff_dv_vlc_len[i];
    int has_level = !!level;

    if (run >= 64)
        continue;
    struct dv_vlc_pair* target = &dv_vlc_map[run][level];
    if (target->size != 0)
        continue;

    // Precompute shift and size to reduce repeated access
    target->vlc = bits << has_level;
    target->size = len + has_level;
}
}
