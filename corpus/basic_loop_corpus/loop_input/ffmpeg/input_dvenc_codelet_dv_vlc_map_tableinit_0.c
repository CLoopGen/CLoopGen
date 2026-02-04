#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct dv_vlc_pair {
    uint32_t vlc;
    uint32_t size;
};

const uint16_t ff_dv_vlc_bits[409] = {0};
const uint8_t ff_dv_vlc_len[409] = {0};
const uint8_t ff_dv_vlc_run[409] = {0};
const uint8_t ff_dv_vlc_level[409] = {0};
struct dv_vlc_pair dv_vlc_map[64][512];
int i;

static uint16_t internal_ff_dv_vlc_bits[409];
static uint8_t internal_ff_dv_vlc_len[409];
static uint8_t internal_ff_dv_vlc_run[409];
static uint8_t internal_ff_dv_vlc_level[409];

void init_vars() {
    for (int j = 0; j < 409; j++) {
        internal_ff_dv_vlc_bits[j] = (uint16_t)(rand() & 0xFFFF);
        internal_ff_dv_vlc_len[j] = (uint8_t)(rand() & 0xFF);
        internal_ff_dv_vlc_run[j] = (uint8_t)(rand() % 65); // Ensure run < 64 or == 64 to trigger condition
        internal_ff_dv_vlc_level[j] = (uint8_t)(rand() % 512);
    }

    memcpy((void *)internal_ff_dv_vlc_bits, internal_ff_dv_vlc_bits, sizeof(internal_ff_dv_vlc_bits));
    memcpy((void *)internal_ff_dv_vlc_len, internal_ff_dv_vlc_len, sizeof(internal_ff_dv_vlc_len));
    memcpy((void *)internal_ff_dv_vlc_run, internal_ff_dv_vlc_run, sizeof(internal_ff_dv_vlc_run));
    memcpy((void *)internal_ff_dv_vlc_level, internal_ff_dv_vlc_level, sizeof(internal_ff_dv_vlc_level));

    for (int run = 0; run < 64; run++) {
        for (int level = 0; level < 512; level++) {
            dv_vlc_map[run][level].vlc = 0;
            dv_vlc_map[run][level].size = 0;
        }
    }

    i = 0;
}