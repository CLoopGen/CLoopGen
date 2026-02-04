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

RL_VLC_ELEM rl_vlc_table[32][552];

uint16_t table_vlc_data[1024][2];
int8_t table_run_data[1024];
int8_t table_level_data[1024];
uint8_t index_run_data[2][1024];
int8_t max_level_data[2][1024];
int8_t max_run_data[2][1024];

RLTable ff_h261_rl_tcoeff = {
    .n = 0,
    .last = 0,
    .table_vlc = table_vlc_data,
    .table_run = table_run_data,
    .table_level = table_level_data,
    .index_run = { index_run_data[0], index_run_data[1] },
    .max_level = { max_level_data[0], max_level_data[1] },
    .max_run = { max_run_data[0], max_run_data[1] },
    .rl_vlc = { NULL }
};

int q;

void init_vars() {
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 552; ++j) {
            rl_vlc_table[i][j].level = (int16_t)(j % 32768);
            rl_vlc_table[i][j].len = (int8_t)(j % 128);
            rl_vlc_table[i][j].run = (uint8_t)(j % 256);
        }
    }

    for (int i = 0; i < 1024; ++i) {
        table_vlc_data[i][0] = (uint16_t)(i % 32768);
        table_vlc_data[i][1] = (uint16_t)((i + 1) % 32768);
        table_run_data[i] = (int8_t)(i % 128);
        table_level_data[i] = (int8_t)((i * 3) % 128);
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 1024; ++j) {
            index_run_data[i][j] = (uint8_t)(j % 256);
            max_level_data[i][j] = (int8_t)(j % 128);
            max_run_data[i][j] = (int8_t)((j * 2) % 128);
        }
    }

    for (int i = 0; i < 32; ++i) {
        ff_h261_rl_tcoeff.rl_vlc[i] = NULL;
    }

    q = 0;
}