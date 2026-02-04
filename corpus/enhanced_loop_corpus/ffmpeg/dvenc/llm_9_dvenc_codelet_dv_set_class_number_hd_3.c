#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct EncBlockInfo {
    int area_q[4];
    int bit_size[4];
    int prev[5];
    int cur_ac;
    int cno;
    int dct_mode;
    int16_t mb[64];
    uint8_t next[64];
    uint8_t sign[64];
    uint8_t partial_bit_count;
    uint32_t partial_bit_buffer;
    int16_t save[64];
    int min_qlevel;
} EncBlockInfo;

extern int16_t *blk;
extern EncBlockInfo *bi;
extern  uint8_t *zigzag_scan;
extern  int *weight;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 4;
for (i = 0; i < 64; i += stride) {
    int level0, level1, level2, level3;
    level0 = blk[zigzag_scan[i + 0]];
    level1 = blk[zigzag_scan[i + 1]];
    level2 = blk[zigzag_scan[i + 2]];
    level3 = blk[zigzag_scan[i + 3]];
    bi->sign[i + 0] = (level0 >> 31) & 1;
    bi->sign[i + 1] = (level1 >> 31) & 1;
    bi->sign[i + 2] = (level2 >> 31) & 1;
    bi->sign[i + 3] = (level3 >> 31) & 1;
    level0 = (level0 >= 0) ? level0 : -level0;
    level1 = (level1 >= 0) ? level1 : -level1;
    level2 = (level2 >= 0) ? level2 : -level2;
    level3 = (level3 >= 0) ? level3 : -level3;
    level0 = (level0 * weight[i + 0] + 4096 + (1 << 17)) >> 18;
    level1 = (level1 * weight[i + 1] + 4096 + (1 << 17)) >> 18;
    level2 = (level2 * weight[i + 2] + 4096 + (1 << 17)) >> 18;
    level3 = (level3 * weight[i + 3] + 4096 + (1 << 17)) >> 18;
    bi->save[i + 0] = level0;
    bi->save[i + 1] = level1;
    bi->save[i + 2] = level2;
    bi->save[i + 3] = level3;
    if (level0 > max) max = level0;
    if (level1 > max) max = level1;
    if (level2 > max) max = level2;
    if (level3 > max) max = level3;
}
}
