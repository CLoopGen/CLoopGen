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
    // Variant 2: Strided memory access — process elements in reverse with stride of 2 for scattered access
    for (q = 0; q < 32; q++) {
        int qmul = q * 2;
        int qadd = (q - 1) | 1;
        if (q == 0) {
            qmul = 1;
            qadd = 0;
        }
        // Reverse traversal with stride of 2 (strided access pattern)
        int i;
        int step = 2;
        int start = (vlc.table_size - 1) & ~1; // Round down to even index
        RL_VLC_ELEM *rl_vlc_base = rl->rl_vlc[q];
        for (i = start; i >= 0; i -= step) {
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
            rl_vlc_base[i].len = len;
            rl_vlc_base[i].level = level;
            rl_vlc_base[i].run = run;

            // Handle odd index if within bounds
            int i_prev = i - 1;
            if (i_prev >= 0) {
                code = vlc.table[i_prev][0];
                len = vlc.table[i_prev][1];
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
                rl_vlc_base[i_prev].len = len;
                rl_vlc_base[i_prev].level = level;
                rl_vlc_base[i_prev].run = run;
            }
        }
        // Handle case where table_size is odd and first element wasn't processed
        if (vlc.table_size % 2 == 1) {
            i = 0;
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
            rl->rl_vlc[q][i].len = len;
            rl->rl_vlc[q][i].level = level;
            rl->rl_vlc[q][i].run = run;
        }
    }
}
