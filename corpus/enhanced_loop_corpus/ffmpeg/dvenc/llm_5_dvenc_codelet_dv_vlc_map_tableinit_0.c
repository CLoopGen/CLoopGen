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
for (i = 0; i < 409 - 1; i++) {
    int run = ff_dv_vlc_run[i];
    int level = ff_dv_vlc_level[i];
    if (run >= 64) {
        continue;
    }
    struct dv_vlc_pair* entry = &dv_vlc_map[run][level];
    if (entry->size == 0) {
        uint32_t vlc_val = ff_dv_vlc_bits[i];
        uint32_t len_val = ff_dv_vlc_len[i];
        if (level != 0) {
            vlc_val <<= 1;
            len_val += 1;
        }
        entry->vlc = vlc_val;
        entry->size = len_val;
    }
}
}
