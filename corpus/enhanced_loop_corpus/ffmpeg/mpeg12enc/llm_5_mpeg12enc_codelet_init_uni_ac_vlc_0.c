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
for (i = 0; i < 128; i++) {
    int level = i - 64;
    int alevel = (level >= 0) ? level : -level;
    int run;
    for (run = 0; run < 64; run++) {
        int len;
        int max_lev = rl->max_level[0][run];
        int index = rl->index_run[0][run] + alevel - 1;
        int use_escape = (alevel > max_lev) || (index >= 111);
        if (use_escape) {
            len = rl->table_vlc[111][1] + 6;
            len += (alevel < 128) ? 8 : 16;
        } else {
            len = rl->table_vlc[index][1] + 1;
        }
        uni_ac_vlc_len[(run * 128 + i)] = len;
    }
}
}
