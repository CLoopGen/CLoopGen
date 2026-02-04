#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RL_VLC_ELEM {
    int16_t level;
    int8_t len;
    uint8_t run;
} RL_VLC_ELEM;

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

RL_VLC_ELEM ff_dv_rl_vlc[1664];
int i;
VLC dv_vlc;
uint8_t new_dv_vlc_run[818];
int16_t new_dv_vlc_level[818];

static int16_t internal_table_memory[2048][2];

void init_vars() {
    dv_vlc.bits = 12;
    dv_vlc.table = internal_table_memory;
    dv_vlc.table_size = 1664;
    dv_vlc.table_allocated = 2048;

    for (int idx = 0; idx < 1664; idx++) {
        dv_vlc.table[idx][0] = idx % 818;
        dv_vlc.table[idx][1] = (idx % 2) ? -(idx % 5) : (idx % 7);
    }

    for (int idx = 0; idx < 818; idx++) {
        new_dv_vlc_run[idx] = idx % 255;
        new_dv_vlc_level[idx] = (int16_t)(idx % 32767);
    }

    for (int idx = 0; idx < 1664; idx++) {
        ff_dv_rl_vlc[idx].level = 0;
        ff_dv_rl_vlc[idx].len = 0;
        ff_dv_rl_vlc[idx].run = 0;
    }

    i = 0;
}