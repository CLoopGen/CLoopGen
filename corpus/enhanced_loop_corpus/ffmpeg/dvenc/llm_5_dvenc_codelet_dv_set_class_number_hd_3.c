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
for (i = 0; i < 64; i += 2) {
    int level0, level1;
    int idx0 = zigzag_scan[i + 0];
    int idx1 = zigzag_scan[i + 1];
    level0 = blk[idx0];
    level1 = blk[idx1];

    // Combine sign extraction and absolute value in one step using conditional update
    if (level0 < 0) {
        bi->sign[i + 0] = 1;
        level0 = -level0;
    } else {
        bi->sign[i + 0] = 0;
    }

    if (level1 < 0) {
        bi->sign[i + 1] = 1;
        level1 = -level1;
    } else {
        bi->sign[i + 1] = 0;
    }

    level0 = (level0 * weight[i + 0] + 4096 + (1 << 17)) >> 18;
    level1 = (level1 * weight[i + 1] + 4096 + (1 << 17)) >> 18;

    bi->save[i + 0] = level0;
    bi->save[i + 1] = level1;

    // Only update max if either value exceeds current max
    if (level0 > max || level1 > max) {
        if (level0 > max) max = level0;
        if (level1 > max) max = level1;
    }
}
}
