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

RLTable ff_mpeg4_rl_intra;

int q;

static uint16_t dummy_table_vlc[512][2];
static int8_t dummy_table_run[512];
static int8_t dummy_table_level[512];
static uint8_t dummy_index_run_data[2][256];
static int8_t dummy_max_level_data[2][256];
static int8_t dummy_max_run_data[2][256];

void init_vars() {
    ff_mpeg4_rl_intra.n = 512;
    ff_mpeg4_rl_intra.last = 511;
    ff_mpeg4_rl_intra.table_vlc = dummy_table_vlc;
    ff_mpeg4_rl_intra.table_run = dummy_table_run;
    ff_mpeg4_rl_intra.table_level = dummy_table_level;

    for (int i = 0; i < 2; i++) {
        ff_mpeg4_rl_intra.index_run[i] = dummy_index_run_data[i];
        ff_mpeg4_rl_intra.max_level[i] = dummy_max_level_data[i];
        ff_mpeg4_rl_intra.max_run[i] = dummy_max_run_data[i];
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 554; j++) {
            rl_vlc_table[i][j].level = (int16_t)(j % 128);
            rl_vlc_table[i][j].len = (int8_t)(j % 128 - 64);
            rl_vlc_table[i][j].run = (uint8_t)(j % 64);
        }
        ff_mpeg4_rl_intra.rl_vlc[i] = NULL;
    }

    q = 0;
}