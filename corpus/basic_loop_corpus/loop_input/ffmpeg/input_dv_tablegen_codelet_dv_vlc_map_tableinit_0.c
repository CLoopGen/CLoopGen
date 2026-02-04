#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

const uint16_t ff_dv_vlc_bits[409] = {0};
const uint8_t ff_dv_vlc_len[409] = {0};
const uint8_t ff_dv_vlc_run[409] = {0};
const uint8_t ff_dv_vlc_level[409] = {0};

struct dv_vlc_pair {
    uint32_t vlc;
    uint32_t size;
};

struct dv_vlc_pair dv_vlc_map[64][512];
int i;

void init_vars() {
    uint16_t temp_bits[409];
    uint8_t temp_len[409];
    uint8_t temp_run[409];
    uint8_t temp_level[409];

    for (int j = 0; j < 409; j++) {
        temp_bits[j] = (uint16_t)(j * 789);
        temp_len[j] = (uint8_t)(1 + (j % 16));
        temp_run[j] = (uint8_t)(j % 65);
        temp_level[j] = (uint8_t)(j % 512);
    }

    memcpy((void*)temp_run, temp_run, sizeof(temp_run));
    memcpy((void*)temp_level, temp_level, sizeof(temp_level));

    for (int run = 0; run < 64; run++) {
        for (int level = 0; level < 512; level++) {
            dv_vlc_map[run][level].vlc = 0;
            dv_vlc_map[run][level].size = 0;
        }
    }

    i = 0;
}