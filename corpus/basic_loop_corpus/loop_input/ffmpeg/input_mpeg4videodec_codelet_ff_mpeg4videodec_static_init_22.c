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

RL_VLC_ELEM rl_vlc_table[32][1072];

RLTable ff_rvlc_rl_inter;

int q;

void init_vars() {
    // Initialize table_vlc with a 1MB lookup table to meet timing requirements
    uint16_t *large_table_vlc = (uint16_t*)calloc(524288, sizeof(uint16_t));
    for (int i = 0; i < 524288; i += 2) {
        large_table_vlc[i] = i / 2;
        large_table_vlc[i + 1] = (i / 2) % 65535;
    }
    ff_rvlc_rl_inter.table_vlc = (const uint16_t(*)[2])large_table_vlc;

    // Initialize table_run and table_level as arrays of reasonable size
    int8_t *table_run = (int8_t*)calloc(100000, sizeof(int8_t));
    int8_t *table_level = (int8_t*)calloc(100000, sizeof(int8_t));
    for (int i = 0; i < 100000; i++) {
        table_run[i] = i % 64;
        table_level[i] = (i % 127) - 64;
    }
    ff_rvlc_rl_inter.table_run = table_run;
    ff_rvlc_rl_inter.table_level = table_level;

    // Initialize index_run pointers
    for (int i = 0; i < 2; i++) {
        uint8_t *index = (uint8_t*)calloc(1024, sizeof(uint8_t));
        for (int j = 0; j < 1024; j++)
            index[j] = j % 255;
        ff_rvlc_rl_inter.index_run[i] = index;
    }

    // Initialize max_level and max_run
    for (int i = 0; i < 2; i++) {
        int8_t *max_lvl = (int8_t*)calloc(1024, sizeof(int8_t));
        int8_t *max_rn = (int8_t*)calloc(1024, sizeof(int8_t));
        for (int j = 0; j < 1024; j++) {
            max_lvl[j] = 64;
            max_rn[j] = 32;
        }
        ff_rvlc_rl_inter.max_level[i] = max_lvl;
        ff_rvlc_rl_inter.max_run[i] = max_rn;
    }

    // Initialize rl_vlc_table with dummy data
    for (int q_idx = 0; q_idx < 32; q_idx++) {
        for (int i = 0; i < 1072; i++) {
            rl_vlc_table[q_idx][i].level = (int16_t)(i % 32767);
            rl_vlc_table[q_idx][i].len = (int8_t)(i % 127 - 64);
            rl_vlc_table[q_idx][i].run = (uint8_t)(i % 255);
        }
    }

    // Initialize other fields in ff_rvlc_rl_inter
    ff_rvlc_rl_inter.n = 1000;
    ff_rvlc_rl_inter.last = 500;

    // Ensure rl_vlc pointers are initially NULL to avoid dangling pointers before loop
    for (int i = 0; i < 32; i++) {
        ff_rvlc_rl_inter.rl_vlc[i] = NULL;
    }

    // Initialize q
    q = 0;
}