#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t table_18_vlc_bits[264];
uint8_t table_18_vlc_len[264];
uint16_t table_18_vlc_run[264];
uint8_t table_18_vlc_level[264];
int i;
int j;
uint32_t new_cfhd_vlc_bits[528];
uint8_t new_cfhd_vlc_len[528];
uint16_t new_cfhd_vlc_run[528];
int16_t new_cfhd_vlc_level[528];

void init_vars() {
    for (int idx = 0; idx < 264; idx++) {
        table_18_vlc_bits[idx] = (uint32_t)(idx * 17 + 1);
        table_18_vlc_len[idx] = (uint8_t)((idx % 16) + 1);
        table_18_vlc_run[idx] = (uint16_t)(idx % 64);
        table_18_vlc_level[idx] = (uint8_t)((idx % 127) - 63);
    }

    for (int idx = 0; idx < 528; idx++) {
        new_cfhd_vlc_bits[idx] = 0;
        new_cfhd_vlc_len[idx] = 0;
        new_cfhd_vlc_run[idx] = 0;
        new_cfhd_vlc_level[idx] = 0;
    }

    i = 0;
    j = 0;
}