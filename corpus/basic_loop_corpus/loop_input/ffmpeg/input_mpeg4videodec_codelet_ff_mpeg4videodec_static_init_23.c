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
RLTable ff_rvlc_rl_intra;
int q;

void init_vars() {
    // Initialize table_vlc with a valid allocation
    uint16_t (*table_vlc_ptr)[2] = malloc(2048 * sizeof(*table_vlc_ptr));
    if (!table_vlc_ptr) exit(1);
    ff_rvlc_rl_intra.table_vlc = table_vlc_ptr;

    // Initialize table_run and table_level
    int8_t *table_run_ptr = malloc(512);
    int8_t *table_level_ptr = malloc(512);
    if (!table_run_ptr || !table_level_ptr) exit(1);
    ff_rvlc_rl_intra.table_run = table_run_ptr;
    ff_rvlc_rl_intra.table_level = table_level_ptr;

    // Initialize index_run, max_level, max_run
    for (int i = 0; i < 2; i++) {
        ff_rvlc_rl_intra.index_run[i] = malloc(256);
        ff_rvlc_rl_intra.max_level[i] = malloc(256);
        ff_rvlc_rl_intra.max_run[i] = malloc(256);
        if (!ff_rvlc_rl_intra.index_run[i] || !ff_rvlc_rl_intra.max_level[i] || !ff_rvlc_rl_intra.max_run[i])
            exit(1);
    }

    // Initialize each entry in rl_vlc_table to avoid undefined behavior
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 1072; j++) {
            rl_vlc_table[i][j].level = j % 32768;
            rl_vlc_table[i][j].len = j % 128;
            rl_vlc_table[i][j].run = j % 256;
        }
    }

    // Ensure the loop runs over full range without out-of-bounds access
    ff_rvlc_rl_intra.n = 32;
    ff_rvlc_rl_intra.last = 1071;

    // No need to initialize ff_rvlc_rl_intra.rl_vlc[q] here — it will be set by loop()
}