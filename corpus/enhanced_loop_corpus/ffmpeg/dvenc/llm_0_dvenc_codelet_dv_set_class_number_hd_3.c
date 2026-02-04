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
    for (int outer = 0; outer < 32; outer++) {
        int i = outer * 2;
        int level0, level1;
        level0 = blk[zigzag_scan[i + 0]];
        level1 = blk[zigzag_scan[i + 1]];
        bi->sign[i + 0] = (level0 >> 31) & 1;
        bi->sign[i + 1] = (level1 >> 31) & 1;
        level0 = ((level0) >= 0 ? (level0) : (-(level0)));
        level1 = ((level1) >= 0 ? (level1) : (-(level1)));
        level0 = (level0 * weight[i + 0] + 4096 + (1 << 17)) >> 18;
        level1 = (level1 * weight[i + 1] + 4096 + (1 << 17)) >> 18;
        bi->save[i + 0] = level0;
        bi->save[i + 1] = level1;
        if (bi->save[i + 0] > max)
            max = bi->save[i + 0];
        if (bi->save[i + 1] > max)
            max = bi->save[i + 1];
    }
}
