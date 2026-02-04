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
        int idx0 = zigzag_scan[i];
        int idx1 = zigzag_scan[i + 1];
        level0 = blk[idx0];
        level1 = blk[idx1];

        int sign0 = (level0 >> 31) & 1;
        int sign1 = (level1 >> 31) & 1;
        level0 = (level0 >= 0) ? level0 : -level0;
        level1 = (level1 >= 0) ? level1 : -level1;

        level0 = (level0 * weight[i] + 4096 + (1 << 17)) >> 18;
        level1 = (level1 * weight[i + 1] + 4096 + (1 << 17)) >> 18;

        bi->save[i] = level0;
        bi->save[i + 1] = level1;

        bi->sign[i] = sign0;
        bi->sign[i + 1] = sign1;

        int local_max = max;
        if (bi->save[i] > local_max)
            local_max = bi->save[i];
        if (bi->save[i + 1] > local_max)
            local_max = bi->save[i + 1];
        max = local_max;
    }
}
