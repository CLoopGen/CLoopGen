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

RL_VLC_ELEM rl_vlc_table[32][940];
RLTable ff_rl_table[6];
int q;

void init_vars() {
    for (int i = 0; i < 6; i++) {
        ff_rl_table[i].n = 0;
        ff_rl_table[i].last = 0;
        ff_rl_table[i].table_vlc = NULL;
        ff_rl_table[i].table_run = NULL;
        ff_rl_table[i].table_level = NULL;
        for (int j = 0; j < 2; j++) {
            ff_rl_table[i].index_run[j] = NULL;
            ff_rl_table[i].max_level[j] = NULL;
            ff_rl_table[i].max_run[j] = NULL;
        }
        for (int j = 0; j < 32; j++) {
            ff_rl_table[i].rl_vlc[j] = NULL;
        }
    }

    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 940; j++) {
            rl_vlc_table[i][j].level = (int16_t)(j % 512);
            rl_vlc_table[i][j].len = (int8_t)(j % 128);
            rl_vlc_table[i][j].run = (uint8_t)(j % 64);
        }
    }
}