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
// Use strided access pattern: process every 8th element in a round-robin fashion across two interleaved streams
for (int stride = 0; stride < 8; stride++) {
    for (i = stride; i < 64; i += 8) {
        int level0, level1;
        int j = i + ((i % 2 == 0) ? 0 : -1); // Align to even index
        if (j >= 64 - 1) continue;

        level0 = blk[zigzag_scan[j]];
        level1 = blk[zigzag_scan[j + 1]];

        bi->sign[j] = (level0 >> 31) & 1;
        bi->sign[j + 1] = (level1 >> 31) & 1;

        level0 = (level0 >= 0) ? level0 : -level0;
        level1 = (level1 >= 0) ? level1 : -level1;

        level0 = (level0 * weight[j] + 4096 + (1 << 17)) >> 18;
        level1 = (level1 * weight[j + 1] + 4096 + (1 << 17)) >> 18;

        bi->save[j] = level0;
        bi->save[j + 1] = level1;

        if (bi->save[j] > max)
            max = bi->save[j];
        if (bi->save[j + 1] > max)
            max = bi->save[j + 1];
    }
}
}
