#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sb_sample_f[16][2][8];
extern int blocks;
extern int blk;
extern int32_t tmp0;
extern int32_t tmp1;
extern uint32_t x;
extern uint32_t y;
extern int sb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (blk = 0; blk < blocks; blk += 2) {
    if (blk + 1 < blocks) {
        tmp0 = (sb_sample_f[blk][0][sb] >= 0) ? sb_sample_f[blk][0][sb] : (-sb_sample_f[blk][0][sb]);
        tmp1 = (sb_sample_f[blk][1][sb] >= 0) ? sb_sample_f[blk][1][sb] : (-sb_sample_f[blk][1][sb]);
        int32_t tmp2 = (sb_sample_f[blk+1][0][sb] >= 0) ? sb_sample_f[blk+1][0][sb] : (-sb_sample_f[blk+1][0][sb]);
        int32_t tmp3 = (sb_sample_f[blk+1][1][sb] >= 0) ? sb_sample_f[blk+1][1][sb] : (-sb_sample_f[blk+1][1][sb]);
        if (tmp0 != 0) x |= tmp0 - 1;
        if (tmp1 != 0) y |= tmp1 - 1;
        if (tmp2 != 0) x |= tmp2 - 1;
        if (tmp3 != 0) y |= tmp3 - 1;
    } else {
        tmp0 = (sb_sample_f[blk][0][sb] >= 0) ? sb_sample_f[blk][0][sb] : (-sb_sample_f[blk][0][sb]);
        tmp1 = (sb_sample_f[blk][1][sb] >= 0) ? sb_sample_f[blk][1][sb] : (-sb_sample_f[blk][1][sb]);
        if (tmp0 != 0) x |= tmp0 - 1;
        if (tmp1 != 0) y |= tmp1 - 1;
    }
}
}
