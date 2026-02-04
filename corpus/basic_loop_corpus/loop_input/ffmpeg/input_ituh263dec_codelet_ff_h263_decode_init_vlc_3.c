#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct RL_VLC_ELEM {
    int16_t level;
    int8_t len;
    uint8_t run;
} RL_VLC_ELEM;

typedef struct RLTable {
    int n;
    int last;
    const uint16_t (*table_vlc)[2];
    const int8_t *table_run;
    const int8_t *table_level;
    uint8_t *index_run[2];
    int8_t *max_level[2];
    int8_t *max_run[2];
    RL_VLC_ELEM *rl_vlc[32];
} RLTable;

RL_VLC_ELEM rl_vlc_table[32][554];

uint16_t dummy_table_vlc[512][2];
int8_t dummy_table_run[512];
int8_t dummy_table_level[512];
uint8_t dummy_index_run0[2][512];
int8_t dummy_max_level0[2][512];
int8_t dummy_max_run0[2][512];

RLTable ff_h263_rl_inter = {
    .n = 512,
    .last = 511,
    .table_vlc = dummy_table_vlc,
    .table_run = dummy_table_run,
    .table_level = dummy_table_level,
    .index_run = { dummy_index_run0[0], dummy_index_run0[1] },
    .max_level = { dummy_max_level0[0], dummy_max_level0[1] },
    .max_run = { dummy_max_run0[0], dummy_max_run0[1] },
    .rl_vlc = { NULL }
};

int q;

void init_vars() {
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 554; j++) {
            rl_vlc_table[i][j].level = (int16_t)(j % 32768);
            rl_vlc_table[i][j].len = (int8_t)(j % 128);
            rl_vlc_table[i][j].run = (uint8_t)(j % 256);
        }
    }
    for (int i = 0; i < 512; i++) {
        dummy_table_vlc[i][0] = (uint16_t)(i & 0xFFFF);
        dummy_table_vlc[i][1] = (uint16_t)((i + 1) & 0xFFFF);
        dummy_table_run[i] = (int8_t)(i % 128);
        dummy_table_level[i] = (int8_t)(i % 128);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 512; j++) {
            dummy_index_run0[i][j] = (uint8_t)(j % 256);
            dummy_max_level0[i][j] = (int8_t)(j % 128);
            dummy_max_run0[i][j] = (int8_t)(j % 128);
        }
    }
}