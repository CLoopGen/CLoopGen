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
    // Reorder loops: iterate over run first, then i (changed memory access pattern to be more cache-friendly for uni_ac_vlc_len)
    int run;
    for (run = 0; run < 64; run++) {
        const uint16_t (*table_vlc)[2] = rl->table_vlc;
        const uint8_t* index_run_0 = rl->index_run[0];
        const int8_t* max_level_0 = rl->max_level[0];
        int max_code_access = 111;
        int base_len_overflow = table_vlc[max_code_access][1] + 6;

        for (i = 0; i < 128; i++) {
            int level = i - 64;
            if (!level) continue;

            int len, code;
            int alevel = (level >= 0 ? level : -level);

            if (alevel > max_level_0[run])
                code = max_code_access;
            else
                code = index_run_0[run] + alevel - 1;

            if (code < max_code_access) {
                len = table_vlc[code][1] + 1;
            } else {
                len = base_len_overflow;
                if (alevel < 128)
                    len += 8;
                else
                    len += 16;
            }

            // Stride changed: sequential in 'i' for fixed 'run' → consecutive writes
            uni_ac_vlc_len[(run * 128 + i)] = len;
        }
    }
}
