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
for (i = 0; i < 64; i++) {
    int level;
    level = blk[zigzag_scan[i]];
    bi->sign[i] = (level >> 31) & 1;
    level = ((level) >= 0 ? (level) : (-(level)));
    level = (level * weight[i] + 4096 + (1 << 17)) >> 18;
    bi->save[i] = level;
    if (bi->save[i] > max)
        max = bi->save[i];
}
}
