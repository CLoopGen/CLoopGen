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
    // Variant 2: Strided memory access with reversed and strided write to rl_vlc[0], writing every second element forward, then filling backward
    RL_VLC_ELEM *base = rl->rl_vlc[0];
    int stride = 2;
    int size = vlc.table_size;

    // First pass: forward strided write (even indices)
    for (i = 0; i < size; i += stride) {
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
        base[i].len = len;
        base[i].level = level;
        base[i].run = run;
    }

    // Second pass: backward fill for odd indices (reverse strided access)
    for (i = (size % 2 == 0) ? size - 1 : size - 2; i > 0; i -= stride) {
        int idx = i;
        int code = vlc.table[idx][0];
        int len = vlc.table[idx][1];
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
        base[idx].len = len;
        base[idx].level = level;
        base[idx].run = run;
    }
}
