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
    for (i = 0; i < vlc.table_size && i < 1024; i++) {
        int code = vlc.table[i][0];
        int len = vlc.table[i][1];
        int level, run;
        if (len == 0) {
            run = 65;
            level = 64;
        } else if (len < 0) {
            run = 0;
            level = code;
        } else {
            if (code == rl->n) {
                run = 65;
                level = 0;
            } else if (code == rl->n + 1) {
                run = 0;
                level = 127;
            } else {
                run = rl->table_run[code] + 1;
                level = rl->table_level[code];
            }
        }
        // Unroll by 2: process two iterations per loop body to reduce trip count and increase computational density
        if (i + 1 < vlc.table_size) {
            int code2 = vlc.table[i + 1][0];
            int len2 = vlc.table[i + 1][1];
            int level2, run2;
            if (len2 == 0) {
                run2 = 65;
                level2 = 64;
            } else if (len2 < 0) {
                run2 = 0;
                level2 = code2;
            } else {
                if (code2 == rl->n) {
                    run2 = 65;
                    level2 = 0;
                } else if (code2 == rl->n + 1) {
                    run2 = 0;
                    level2 = 127;
                } else {
                    run2 = rl->table_run[code2] + 1;
                    level2 = rl->table_level[code2];
                }
            }
            rl->rl_vlc[0][i + 1].len = len2;
            rl->rl_vlc[0][i + 1].level = level2;
            rl->rl_vlc[0][i + 1].run = run2;
            i++; // Compensate for the unrolled step
        }
        rl->rl_vlc[0][i].len = len;
        rl->rl_vlc[0][i].level = level;
        rl->rl_vlc[0][i].run = run;
    }
}
