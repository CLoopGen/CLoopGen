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
    int* cached_run = (int*)alloca(vlc.table_size * sizeof(int));
    int* cached_level = (int*)alloca(vlc.table_size * sizeof(int));
    int* cached_len = (int*)alloca(vlc.table_size * sizeof(int));

    for (i = 0; i < vlc.table_size; i++) {
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

        cached_len[i] = len;
        cached_level[i] = level;
        cached_run[i] = run;
    }

    for (i = 0; i < vlc.table_size; i++) {
        rl->rl_vlc[0][i].len = cached_len[i];
        rl->rl_vlc[0][i].level = cached_level[i];
        rl->rl_vlc[0][i].run = cached_run[i];
    }
}
