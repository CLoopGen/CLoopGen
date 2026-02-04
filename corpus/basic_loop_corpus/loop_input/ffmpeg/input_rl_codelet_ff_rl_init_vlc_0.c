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

typedef struct VLC {
    int bits;
    int16_t (*table)[2];
    int table_size;
    int table_allocated;
} VLC;

// Forward declarations for static data
static uint16_t g_table_vlc_data[64][2];
static int8_t g_table_run_data[64];
static int8_t g_table_level_data[64];
static uint8_t g_index_run_data[2][256];
static int8_t g_max_level_data[2][256];
static int8_t g_max_run_data[2][256];
static RL_VLC_ELEM g_rl_vlc_data[32][1024];
static int16_t g_vlc_table_data[1024][2];

// Define external variables
RLTable *rl;
int i;
int q;
VLC vlc;

void init_vars() {
    // Allocate and initialize rl
    static RLTable rl_instance;
    rl = &rl_instance;

    // Initialize basic fields
    rl->n = 63;
    rl->last = 60;

    // Point to pre-allocated constant data
    rl->table_vlc = g_table_vlc_data;
    rl->table_run = g_table_run_data;
    rl->table_level = g_table_level_data;

    for (int idx = 0; idx < 2; idx++) {
        rl->index_run[idx] = g_index_run_data[idx];
        rl->max_level[idx] = g_max_level_data[idx];
        rl->max_run[idx] = g_max_run_data[idx];
    }

    // Initialize rl_vlc pointers to point to allocated arrays
    for (int q_idx = 0; q_idx < 32; q_idx++) {
        rl->rl_vlc[q_idx] = g_rl_vlc_data[q_idx];
    }

    // Initialize VLC
    vlc.bits = 9;
    vlc.table = g_vlc_table_data;
    vlc.table_size = 1024;
    vlc.table_allocated = 1024;

    // Initialize table_vlc: dummy data
    for (int j = 0; j < 64; j++) {
        g_table_vlc_data[j][0] = j * 2;
        g_table_vlc_data[j][1] = j + 1;
    }

    // Initialize table_run and table_level
    for (int j = 0; j < 64; j++) {
        g_table_run_data[j] = j % 67;
        g_table_level_data[j] = (j % 127) - 64;
    }

    // Initialize index_run, max_level, max_run (dummy)
    for (int idx = 0; idx < 2; idx++) {
        for (int j = 0; j < 256; j++) {
            g_index_run_data[idx][j] = j % 200;
            g_max_level_data[idx][j] = (j % 127) - 64;
            g_max_run_data[idx][j] = j % 200;
        }
    }

    // Initialize vlc.table with valid codes
    for (int j = 0; j < 1024; j++) {
        if (j < 64) {
            g_vlc_table_data[j][0] = j;
            g_vlc_table_data[j][1] = j + 1;
        } else if (j == 64) {
            g_vlc_table_data[j][0] = rl->n;
            g_vlc_table_data[j][1] = 1;
        } else if (j == 65) {
            g_vlc_table_data[j][0] = 0;
            g_vlc_table_data[j][1] = -1;
        } else {
            g_vlc_table_data[j][0] = 0;
            g_vlc_table_data[j][1] = 0;
        }
    }

    // Ensure rl_vlc arrays are zero-initialized via static allocation
}