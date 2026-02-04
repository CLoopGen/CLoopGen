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
for (blk = 0; blk < blocks; blk++) {
    tmp0 = sb_sample_f[blk][0][sb];
    tmp1 = sb_sample_f[blk][1][sb];
    tmp0 = (tmp0 ^ (tmp0 >> 31)) - (tmp0 >> 31); // Fast abs for int32_t using bitwise operations
    tmp1 = (tmp1 ^ (tmp1 >> 31)) - (tmp1 >> 31);
    x |= (tmp0 != 0) ? (tmp0 - 1) : 0;
    y |= (tmp1 != 0) ? (tmp1 - 1) : 0;
}
}
