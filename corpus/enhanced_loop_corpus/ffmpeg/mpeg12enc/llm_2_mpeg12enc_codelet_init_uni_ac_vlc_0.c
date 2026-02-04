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
    for (i = 0; i < 128; i += 2) {
        int level1 = i - 64;
        int level2 = (i + 1) - 64;
        int run;
        if (!level1) {
            // Skip storing when level1 is zero, but process level2 if valid
            if (i + 1 < 128) {
                for (run = 0; run < 64; run++) {
                    int len, code;
                    int alevel = (level2 >= 0 ? level2 : -level2);
                    if (alevel > rl->max_level[0][run])
                        code = 111;
                    else
                        code = rl->index_run[0][run] + alevel - 1;
                    if (code < 111) {
                        len = rl->table_vlc[code][1] + 1;
                    } else {
                        len = rl->table_vlc[111][1] + 6;
                        if (alevel < 128)
                            len += 8;
                        else
                            len += 16;
                    }
                    uni_ac_vlc_len[(run * 128 + (i + 1))] = len;
                }
            }
        } else if (level2 == 0 || i + 1 >= 128) {
            // Only process level1
            for (run = 0; run < 64; run++) {
                int len, code;
                int alevel = (level1 >= 0 ? level1 : -level1);
                if (alevel > rl->max_level[0][run])
                    code = 111;
                else
                    code = rl->index_run[0][run] + alevel - 1;
                if (code < 111) {
                    len = rl->table_vlc[code][1] + 1;
                } else {
                    len = rl->table_vlc[111][1] + 6;
                    if (alevel < 128)
                        len += 8;
                    else
                        len += 16;
                }
                uni_ac_vlc_len[(run * 128 + i)] = len;
            }
        } else {
            // Process both level1 and level2 (vectorized-like access)
            for (run = 0; run < 64; run++) {
                int len1, len2, code1, code2;
                int alevel1 = (level1 >= 0 ? level1 : -level1);
                int alevel2 = (level2 >= 0 ? level2 : -level2);

                if (alevel1 > rl->max_level[0][run])
                    code1 = 111;
                else
                    code1 = rl->index_run[0][run] + alevel1 - 1;

                if (code1 < 111)
                    len1 = rl->table_vlc[code1][1] + 1;
                else {
                    len1 = rl->table_vlc[111][1] + 6;
                    if (alevel1 < 128)
                        len1 += 8;
                    else
                        len1 += 16;
                }

                if (alevel2 > rl->max_level[0][run])
                    code2 = 111;
                else
                    code2 = rl->index_run[0][run] + alevel2 - 1;

                if (code2 < 111)
                    len2 = rl->table_vlc[code2][1] + 1;
                else {
                    len2 = rl->table_vlc[111][1] + 6;
                    if (alevel2 < 128)
                        len2 += 8;
                    else
                        len2 += 16;
                }

                uni_ac_vlc_len[(run * 128 + i)]     = len1;
                if (i + 1 < 128)
                    uni_ac_vlc_len[(run * 128 + i + 1)] = len2;
            }
        }
    }
}
