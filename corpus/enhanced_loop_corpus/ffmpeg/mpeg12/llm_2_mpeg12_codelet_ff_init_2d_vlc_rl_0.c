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

extern RLTable *rl;
extern int i;
extern VLC vlc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic for rl_vlc[0]
    RL_VLC_ELEM *dst = rl->rl_vlc[0];
    const int16_t (*table)[2] = vlc.table;
    const int8_t *run_table = rl->table_run;
    const int8_t *level_table = rl->table_level;
    int n = rl->n;
    for (i = 0; i < vlc.table_size; i++) {
        int code = table[i][0];
        int len = table[i][1];
        int level, run;
        if (len == 0) {
            run = 65;
            level = 64;
        } else if (len < 0) {
            run = 0;
            level = code;
        } else {
            if (code == n) {
                run = 65;
                level = 0;
            } else if (code == n + 1) {
                run = 0;
                level = 127;
            } else {
                run = run_table[code] + 1;
                level = level_table[code];
            }
        }
        dst[i].len = len;
        dst[i].level = level;
        dst[i].run = run;
    }
}
