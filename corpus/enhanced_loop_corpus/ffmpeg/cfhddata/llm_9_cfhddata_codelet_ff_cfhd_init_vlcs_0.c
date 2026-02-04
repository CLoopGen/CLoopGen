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
    int limit = 74;
    for (i = 0; i < limit; i += 2) {
        for (int k = 0; k < 2 && (i + k) < limit; k++) {
            int idx = i + k;
            new_cfhd_vlc_bits[j] = table_9_vlc_bits[idx];
            new_cfhd_vlc_len[j] = table_9_vlc_len[idx];
            new_cfhd_vlc_run[j] = table_9_vlc_run[idx];
            new_cfhd_vlc_level[j] = table_9_vlc_level[idx];

            if (table_9_vlc_level[idx] && table_9_vlc_bits[idx] != table_9_vlc_bits[limit - 1]) {
                uint32_t extended_bits = table_9_vlc_bits[idx] << 1;
                uint8_t extended_len = table_9_vlc_len[idx] + 1;
                j++;
                new_cfhd_vlc_bits[j] = extended_bits;
                new_cfhd_vlc_len[j] = extended_len;
                new_cfhd_vlc_run[j] = table_9_vlc_run[idx];
                new_cfhd_vlc_level[j] = -table_9_vlc_level[idx];
            }
            j++;
        }
    }
}
