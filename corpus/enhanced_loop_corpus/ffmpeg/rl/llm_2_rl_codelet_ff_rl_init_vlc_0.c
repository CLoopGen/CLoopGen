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
    // Variant 1: Consecutive memory access via pointer arithmetic to improve cache locality
    for (q = 0; q < 32; q++) {
        int qmul = q * 2;
        int qadd = (q - 1) | 1;
        if (q == 0) {
            qmul = 1;
            qadd = 0;
        }
        // Use a pointer to traverse vlc.table and rl->rl_vlc[q] consecutively
        int i = 0;
        int16_t (*table_ptr)[2] = vlc.table;
        RL_VLC_ELEM *rl_vlc_ptr = rl->rl_vlc[q];
        for (; i < vlc.table_size; i++) {
            int code = table_ptr[i][0];
            int len = table_ptr[i][1];
            int level, run;
            if (len == 0) {
                run = 66;
                level = 64;
            } else if (len < 0) {
                run = 0;
                level = code;
            } else {
                if (code == rl->n) {
                    run = 66;
                    level = 0;
                } else {
                    run = rl->table_run[code] + 1;
                    level = rl->table_level[code] * qmul + qadd;
                    if (code >= rl->last)
                        run += 192;
                }
            }
            // Direct struct member assignment via pointer
            rl_vlc_ptr[i].len = len;
            rl_vlc_ptr[i].level = level;
            rl_vlc_ptr[i].run = run;
        }
    }
}
