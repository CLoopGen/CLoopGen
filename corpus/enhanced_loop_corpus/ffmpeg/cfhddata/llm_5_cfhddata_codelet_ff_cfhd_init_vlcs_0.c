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
    for (i = 0, j = 0; i < (71 + 3); i++, j++) {
        int has_level = table_9_vlc_level[i];
        int is_not_max_code = (new_cfhd_vlc_bits[j] != table_9_vlc_bits[(71 + 3) - 1]);

        new_cfhd_vlc_bits[j] = table_9_vlc_bits[i];
        new_cfhd_vlc_len[j] = table_9_vlc_len[i];
        new_cfhd_vlc_run[j] = table_9_vlc_run[i];
        new_cfhd_vlc_level[j] = table_9_vlc_level[i];

        j += (has_level && is_not_max_code);
        
        if (has_level && is_not_max_code) {
            new_cfhd_vlc_bits[j] = (table_9_vlc_bits[i] << 1) | 1;
            new_cfhd_vlc_len[j] = table_9_vlc_len[i] + 1;
            new_cfhd_vlc_run[j] = table_9_vlc_run[i];
            new_cfhd_vlc_level[j] = -table_9_vlc_level[i];

            new_cfhd_vlc_bits[j - 1] <<= 1;
            new_cfhd_vlc_len[j - 1]++;
        } else {
            j--;
        }
    }
}
