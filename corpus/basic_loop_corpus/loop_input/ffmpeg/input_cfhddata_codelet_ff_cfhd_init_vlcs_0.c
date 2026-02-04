#include <stdint.h>
#include <string.h>

uint32_t table_9_vlc_bits[74];
uint8_t table_9_vlc_len[74];
uint16_t table_9_vlc_run[74];
uint8_t table_9_vlc_level[74];
int i;
int j;
uint32_t new_cfhd_vlc_bits[528];
uint8_t new_cfhd_vlc_len[528];
uint16_t new_cfhd_vlc_run[528];
int16_t new_cfhd_vlc_level[528];

void init_vars() {
    for (int idx = 0; idx < 74; idx++) {
        table_9_vlc_bits[idx] = (uint32_t)(0xABCDEF00 + idx);
        table_9_vlc_len[idx] = (uint8_t)(1 + (idx % 16));
        table_9_vlc_run[idx] = (uint16_t)(idx * 2);
        table_9_vlc_level[idx] = (uint8_t)(idx % 2 ? -(idx & 0x7F) : (idx & 0x7F));
    }

    memset(new_cfhd_vlc_bits, 0, sizeof(new_cfhd_vlc_bits));
    memset(new_cfhd_vlc_len, 0, sizeof(new_cfhd_vlc_len));
    memset(new_cfhd_vlc_run, 0, sizeof(new_cfhd_vlc_run));
    memset(new_cfhd_vlc_level, 0, sizeof(new_cfhd_vlc_level));

    i = 0;
    j = 0;
}