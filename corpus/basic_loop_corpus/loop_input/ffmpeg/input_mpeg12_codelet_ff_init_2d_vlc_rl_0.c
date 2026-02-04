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

static uint16_t g_table_vlc_data[1024][2];
static int8_t g_table_run_data[1024];
static int8_t g_table_level_data[1024];
static int16_t g_vlc_table_data[65536][2];
static RL_VLC_ELEM g_rl_vlc_elements[32][65536];

RLTable *rl;
int i;
VLC vlc;

void init_vars() {
    rl = (RLTable*)malloc(sizeof(RLTable));
    if (!rl) exit(1);

    rl->n = 1000;
    rl->last = 0;
    rl->table_vlc = g_table_vlc_data;
    rl->table_run = g_table_run_data;
    rl->table_level = g_table_level_data;
    for (int j = 0; j < 2; j++) {
        rl->index_run[j] = (uint8_t*)calloc(256, sizeof(uint8_t));
        rl->max_level[j] = (int8_t*)calloc(256, sizeof(int8_t));
        rl->max_run[j] = (int8_t*)calloc(256, sizeof(int8_t));
    }
    for (int j = 0; j < 32; j++) {
        rl->rl_vlc[j] = j == 0 ? g_rl_vlc_elements[0] : NULL;
    }

    for (int j = 0; j < 1024; j++) {
        g_table_vlc_data[j][0] = j % 65536;
        g_table_vlc_data[j][1] = j % 32;
        g_table_run_data[j] = j % 64;
        g_table_level_data[j] = j % 127;
    }

    vlc.bits = 9;
    vlc.table = g_vlc_table_data;
    vlc.table_size = 65536;
    vlc.table_allocated = 65536;

    for (int j = 0; j < vlc.table_size; j++) {
        g_vlc_table_data[j][0] = rand() % (rl->n + 2);
        g_vlc_table_data[j][1] = (rand() % 17) - 8;
    }

    for (int j = 0; j < 32; j++) {
        for (int k = 0; k < 65536; k++) {
            g_rl_vlc_elements[j][k].level = 0;
            g_rl_vlc_elements[j][k].len = 0;
            g_rl_vlc_elements[j][k].run = 0;
        }
    }
}