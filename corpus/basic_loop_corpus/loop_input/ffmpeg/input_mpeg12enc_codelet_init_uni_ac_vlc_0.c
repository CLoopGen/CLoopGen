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

static uint16_t table_vlc_data[112][2];
static int8_t table_run_data[64];
static int8_t table_level_data[64];
static uint8_t index_run_data[2][64];
static int8_t max_level_data[2][64];
static int8_t max_run_data[2][64];
RL_VLC_ELEM *rl_vlc_pointers[32];

uint8_t *uni_ac_vlc_len;
int i;

RLTable *rl;

void init_vars() {
    // Allocate and initialize table_vlc: needs at least 112 entries
    for (int idx = 0; idx < 112; idx++) {
        table_vlc_data[idx][0] = idx;
        table_vlc_data[idx][1] = (idx == 111) ? 4 : 1; // make code 111 have longer base length
    }

    // Initialize other table data
    for (int j = 0; j < 64; j++) {
        table_run_data[j] = j;
        table_level_data[j] = j;
        index_run_data[0][j] = j > 50 ? 110 : j * 2;
        index_run_data[1][j] = j;
        for (int k = 0; k < 2; k++) {
            max_level_data[k][j] = 64; // ensure alevel <= max_level for most cases
            max_run_data[k][j] = 63;
        }
    }

    // Allocate uni_ac_vlc_len: covers (run*128 + i), run < 64, i < 128 => max index = 64*128 + 127 = 8319
    uni_ac_vlc_len = calloc(8320, sizeof(uint8_t));
    if (!uni_ac_vlc_len) exit(1);

    // Setup rl structure
    rl = malloc(sizeof(RLTable));
    if (!rl) exit(1);

    rl->n = 64;
    rl->last = 63;
    rl->table_vlc = table_vlc_data;
    rl->table_run = table_run_data;
    rl->table_level = table_level_data;
    rl->index_run[0] = index_run_data[0];
    rl->index_run[1] = index_run_data[1];
    rl->max_level[0] = max_level_data[0];
    rl->max_level[1] = max_level_data[1];
    rl->max_run[0] = max_run_data[0];
    rl->max_run[1] = max_run_data[1];
    for (int j = 0; j < 32; j++) {
        rl->rl_vlc[j] = NULL;
    }
}