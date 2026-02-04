#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t table_9_vlc_bits[74];
extern  uint8_t table_9_vlc_len[74];
extern  uint16_t table_9_vlc_run[74];
extern  uint8_t table_9_vlc_level[74];
extern int i;
extern int j;
extern uint32_t new_cfhd_vlc_bits[528];
extern uint8_t new_cfhd_vlc_len[528];
extern uint16_t new_cfhd_vlc_run[528];
extern int16_t new_cfhd_vlc_level[528];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0, j = 0; i < (71 + 3); i++) {
        uint32_t bits = table_9_vlc_bits[i];
        uint8_t len = table_9_vlc_len[i];
        uint16_t run = table_9_vlc_run[i];
        uint8_t level = table_9_vlc_level[i];

        new_cfhd_vlc_bits[j] = bits;
        new_cfhd_vlc_len[j] = len;
        new_cfhd_vlc_run[j] = run;
        new_cfhd_vlc_level[j] = level;

        if (level && bits != table_9_vlc_bits[(71 + 3) - 1]) {
            new_cfhd_vlc_bits[j + 1] = (bits << 1);
            new_cfhd_vlc_len[j + 1] = len + 1;
            new_cfhd_vlc_run[j + 1] = run;
            new_cfhd_vlc_level[j + 1] = -level;

            new_cfhd_vlc_bits[j + 2] = ((bits << 1) | 1);
            new_cfhd_vlc_len[j + 2] = len + 1;
            new_cfhd_vlc_run[j + 2] = run;
            new_cfhd_vlc_level[j + 2] = -level;

            j += 3;
        } else {
            j += 1;
        }
    }
}
