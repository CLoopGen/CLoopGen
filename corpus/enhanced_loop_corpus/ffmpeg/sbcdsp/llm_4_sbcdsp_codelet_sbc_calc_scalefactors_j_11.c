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
for (blk = 0; blk < blocks; blk++) {
    tmp0 = ((sb_sample_j[blk][0]) >= 0 ? (sb_sample_j[blk][0]) : (-(sb_sample_j[blk][0])));
    tmp1 = ((sb_sample_j[blk][1]) >= 0 ? (sb_sample_j[blk][1]) : (-(sb_sample_j[blk][1])));
    x |= (tmp0 != 0) ? (tmp0 - 1) : 0;
    y |= (tmp1 != 0) ? (tmp1 - 1) : 0;
}
}
