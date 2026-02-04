#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t table_18_vlc_bits[264];
extern  uint8_t table_18_vlc_len[264];
extern  uint16_t table_18_vlc_run[264];
extern  uint8_t table_18_vlc_level[264];
extern int i;
extern int j;
extern uint32_t new_cfhd_vlc_bits[528];
extern uint8_t new_cfhd_vlc_len[528];
extern uint16_t new_cfhd_vlc_run[528];
extern int16_t new_cfhd_vlc_level[528];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_bits[2];
    uint8_t temp_len[2];
    uint16_t temp_run;
    int16_t temp_level[2];

    for (i = 0; i < (263 + 1); i++) {
        temp_bits[0] = table_18_vlc_bits[i];
        temp_len[0] = table_18_vlc_len[i];
        temp_run = table_18_vlc_run[i];
        temp_level[0] = table_18_vlc_level[i];
        temp_level[1] = -temp_level[0];

        new_cfhd_vlc_bits[j] = temp_bits[0];
        new_cfhd_vlc_len[j] = temp_len[0];
        new_cfhd_vlc_run[j] = temp_run;
        new_cfhd_vlc_level[j] = temp_level[0];
        j++;

        if (temp_level[0] && temp_bits[0] != table_18_vlc_bits[263]) {
            temp_bits[1] = temp_bits[0] << 1;
            temp_len[1] = temp_len[0] + 1;

            new_cfhd_vlc_bits[j] = temp_bits[1];
            new_cfhd_vlc_len[j] = temp_len[1];
            new_cfhd_vlc_run[j] = temp_run;
            new_cfhd_vlc_level[j] = temp_level[1];
            j++;

            new_cfhd_vlc_bits[j] = (temp_bits[0] << 1) | 1;
            new_cfhd_vlc_len[j] = temp_len[1];
            new_cfhd_vlc_run[j] = temp_run;
            new_cfhd_vlc_level[j] = temp_level[1];
            j++;
        }
    }
}
