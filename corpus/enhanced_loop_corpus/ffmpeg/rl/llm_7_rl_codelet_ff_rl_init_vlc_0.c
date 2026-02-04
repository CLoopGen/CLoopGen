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
// Reverse the loop order to change data access pattern and eliminate loop-carried dependencies in forward direction
for (q = 31; q >= 0; q--) {
    int qmul = q * 2;
    int qadd = (q - 1) | 1;
    if (q == 0) {
        qmul = 1;
        qadd = 0;
    }
    // Modify data dependency by precomputing table values used repeatedly, introducing temporal reuse
    const int8_t *local_run = rl->table_run;
    const int8_t *local_level = rl->table_level;
    int n_limit = rl->n;
    int last_limit = rl->last;
    // Move invariant condition checks outside inner loop where possible
    for (i = vlc.table_size - 1; i >= 0; i--) {
        int code = vlc.table[i][0];
        int len = vlc.table[i][1];
        int level, run;
        if (len == 0) {
            run = 66;
            level = 64;
        } else if (len < 0) {
            run = 0;
            level = code;
        } else {
            if (code == n_limit) {
                run = 66;
                level = 0;
            } else {
                run = local_run[code] + 1;
                level = local_level[code] * qmul + qadd;
                if (code >= last_limit)
                    run += 192;
            }
        }
        // Update structure directly but with reversed access — changes RAW dependency chain direction
        rl->rl_vlc[q][i].len = len;
        rl->rl_vlc[q][i].level = level;
        rl->rl_vlc[q][i].run = run;
    }
}
}
