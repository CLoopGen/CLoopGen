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

uint8_t mpeg1_index_run[2][64];
int8_t mpeg1_max_level[2][64];
int i;

static uint8_t internal_index_run[2][64];
static int8_t internal_max_level[2][64];
static RL_VLC_ELEM internal_rl_vlc_elems[32][64];
static const uint16_t dummy_table_vlc[64][2];

RLTable ff_rl_mpeg1 = {
    .n = 64,
    .last = 63,
    .table_vlc = dummy_table_vlc,
    .table_run = NULL,
    .table_level = NULL,
    .index_run = { internal_index_run[0], internal_index_run[1] },
    .max_level = { internal_max_level[0], internal_max_level[1] },
    .max_run = { NULL, NULL },
};

void init_vars() {
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 64; i++) {
            internal_index_run[j][i] = (uint8_t)(i * 2);
            internal_max_level[j][i] = (int8_t)(i - 32);
        }
    }

    for (int k = 0; k < 32; k++) {
        for (int i = 0; i < 64; i++) {
            internal_rl_vlc_elems[k][i].level = (int16_t)(i * 17);
            internal_rl_vlc_elems[k][i].len = (int8_t)(i % 16);
            internal_rl_vlc_elems[k][i].run = (uint8_t)(i % 64);
        }
        ff_rl_mpeg1.rl_vlc[k] = internal_rl_vlc_elems[k];
    }

    for (int i = 0; i < 64; i++) {
        ((uint16_t (*)[2])dummy_table_vlc)[i][0] = (uint16_t)(i * 3);
        ((uint16_t (*)[2])dummy_table_vlc)[i][1] = (uint16_t)(i * 5);
    }
}