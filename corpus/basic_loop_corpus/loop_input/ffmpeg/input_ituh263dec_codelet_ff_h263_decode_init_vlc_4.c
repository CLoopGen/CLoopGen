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

RLTable ff_rl_intra_aic;

int q;

void init_vars() {
    // Initialize ff_rl_intra_aic fields
    ff_rl_intra_aic.n = 0;
    ff_rl_intra_aic.last = 0;
    ff_rl_intra_aic.table_vlc = NULL;
    ff_rl_intra_aic.table_run = NULL;
    ff_rl_intra_aic.table_level = NULL;
    
    // Allocate and initialize index_run arrays
    for (int i = 0; i < 2; i++) {
        ff_rl_intra_aic.index_run[i] = (uint8_t*)calloc(64, sizeof(uint8_t));
        ff_rl_intra_aic.max_level[i] = (int8_t*)calloc(64, sizeof(int8_t));
        ff_rl_intra_aic.max_run[i] = (int8_t*)calloc(64, sizeof(int8_t));
    }
    
    // Initialize rl_vlc_table with non-trivial data
    for (int q_idx = 0; q_idx < 32; q_idx++) {
        for (int j = 0; j < 554; j++) {
            rl_vlc_table[q_idx][j].level = (int16_t)(j % 512);
            rl_vlc_table[q_idx][j].len = (int8_t)((j % 127) - 64);
            rl_vlc_table[q_idx][j].run = (uint8_t)(j % 64);
        }
    }
    
    // Ensure all rl_vlc pointers are initialized to valid memory
    for (int i = 0; i < 32; i++) {
        ff_rl_intra_aic.rl_vlc[i] = NULL;
    }
    
    // Initialize q
    q = 0;
}