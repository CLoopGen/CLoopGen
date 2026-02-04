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
    int temp_sign[64];
    int temp_save[64];
    for (i = 0; i < 64; i += 2) {
        int level0, level1;
        int idx0 = zigzag_scan[i + 0];
        int idx1 = zigzag_scan[i + 1];
        level0 = blk[idx0];
        level1 = blk[idx1];

        temp_sign[i + 0] = (level0 >> 31) & 1;
        temp_sign[i + 1] = (level1 >> 31) & 1;

        level0 = (level0 >= 0) ? level0 : -level0;
        level1 = (level1 >= 0) ? level1 : -level1;

        level0 = (level0 * weight[i + 0] + 4096 + (1 << 17)) >> 18;
        level1 = (level1 * weight[i + 1] + 4096 + (1 << 17)) >> 18;

        temp_save[i + 0] = level0;
        temp_save[i + 1] = level1;

        if (temp_save[i + 0] > max)
            max = temp_save[i + 0];
        if (temp_save[i + 1] > max)
            max = temp_save[i + 1];
    }
    for (i = 0; i < 64; i++) {
        bi->sign[i] = temp_sign[i];
        bi->save[i] = temp_save[i];
    }
}
