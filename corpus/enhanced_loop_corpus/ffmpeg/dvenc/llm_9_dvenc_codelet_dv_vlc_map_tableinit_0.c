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
    for (i = 0; i < 256; i++) {
        int run = ff_dv_vlc_run[i];
        int level = ff_dv_vlc_level[i];
        if (run < 64) {
            struct dv_vlc_pair* entry = &dv_vlc_map[run][level];
            if (entry->size == 0) {
                uint32_t shift = (level > 0);
                entry->vlc = ff_dv_vlc_bits[i] << shift;
                entry->size = ff_dv_vlc_len[i] + shift;
            }
        }
        if (i + 1 < 409 - 1) {
            int run_next = ff_dv_vlc_run[i + 1];
            int level_next = ff_dv_vlc_level[i + 1];
            if (run_next < 64 && dv_vlc_map[run_next][level_next].size == 0) {
                uint32_t shift_next = (level_next > 0);
                dv_vlc_map[run_next][level_next].vlc = ff_dv_vlc_bits[i + 1] << shift_next;
                dv_vlc_map[run_next][level_next].size = ff_dv_vlc_len[i + 1] + shift_next;
            }
        }
    }
}
