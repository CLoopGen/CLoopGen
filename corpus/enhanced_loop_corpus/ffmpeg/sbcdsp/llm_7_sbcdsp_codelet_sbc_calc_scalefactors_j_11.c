#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int blocks;
extern int blk;
extern int32_t tmp0;
extern int32_t tmp1;
extern uint32_t x;
extern uint32_t y;
extern int32_t sb_sample_j[16][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
x = 0; y = 0;
int32_t local_x = 0, local_y = 0;
for (blk = 0; blk < blocks; blk++) {
    tmp0 = (sb_sample_j[blk][0] < 0) ? -sb_sample_j[blk][0] : sb_sample_j[blk][0];
    tmp1 = (sb_sample_j[blk][1] < 0) ? -sb_sample_j[blk][1] : sb_sample_j[blk][1];
    if (tmp0 != 0)
        local_x |= tmp0 - 1;
    if (tmp1 != 0)
        local_y |= tmp1 - 1;
}
x = local_x;
y = local_y;
}
