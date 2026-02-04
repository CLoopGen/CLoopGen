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

extern RLTable *rl;
extern uint8_t *uni_ac_vlc_len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; i += 2) {
    int level_base = i - 128;
    int run;
    for (run = 0; run < 64; run += 4) {
        int level_offsets[] = {0, 1, -1, 2};
        for (int off_idx = 0; off_idx < 4; off_idx++) {
            int level = level_base + level_offsets[off_idx];
            if (!level) continue;
            int alevel = (level >= 0) ? level : -level;
            int code = (alevel > rl->max_level[0][run]) 
                        ? 111 
                        : rl->index_run[0][run] + alevel - 1;
            int len;
            if (code < 111) {
                len = rl->table_vlc[code][1] + 1;
            } else {
                len = rl->table_vlc[111][1] + 6 + ((alevel < 128) ? 8 : 16);
            }
            uni_ac_vlc_len[(run * 128 + i + off_idx)] = len;
        }
    }
}
}
