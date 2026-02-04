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
extern int q;
extern VLC vlc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int q = 0; q < 32; q++) {
    int qmul = q * 2;
    int qadd = (q - 1) | 1;
    if (q == 0) {
        qmul = 1;
        qadd = 0;
    }
    int i = 0;
    for (; i < vlc.table_size; i += 2) {
        int code0 = vlc.table[i][0];
        int len0 = vlc.table[i][1];
        int level0, run0;
        if (len0 == 0) {
            run0 = 66;
            level0 = 64;
        } else if (len0 < 0) {
            run0 = 0;
            level0 = code0;
        } else {
            if (code0 == rl->n) {
                run0 = 66;
                level0 = 0;
            } else {
                run0 = rl->table_run[code0] + 1;
                level0 = rl->table_level[code0] * qmul + qadd;
                if (code0 >= rl->last)
                    run0 += 192;
            }
        }
        rl->rl_vlc[q][i].len = len0;
        rl->rl_vlc[q][i].level = level0;
        rl->rl_vlc[q][i].run = run0;

        if (i + 1 < vlc.table_size) {
            int code1 = vlc.table[i + 1][0];
            int len1 = vlc.table[i + 1][1];
            int level1, run1;
            if (len1 == 0) {
                run1 = 66;
                level1 = 64;
            } else if (len1 < 0) {
                run1 = 0;
                level1 = code1;
            } else {
                if (code1 == rl->n) {
                    run1 = 66;
                    level1 = 0;
                } else {
                    run1 = rl->table_run[code1] + 1;
                    level1 = rl->table_level[code1] * qmul + qadd;
                    if (code1 >= rl->last)
                        run1 += 192;
                }
            }
            rl->rl_vlc[q][i + 1].len = len1;
            rl->rl_vlc[q][i + 1].level = level1;
            rl->rl_vlc[q][i + 1].run = run1;
        }
    }
}
}
