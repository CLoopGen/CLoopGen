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
    int32_t val0 = sb_sample_f[blk][0][sb];
    int32_t val1 = sb_sample_f[blk][1][sb];
    tmp0 = val0 ^ (val0 >> 31); // Fast absolute value using bitwise: flips if negative, works for two's complement
    tmp1 = val1 ^ (val1 >> 31);
    if (tmp0 != 0)
        x |= tmp0 - 1;
    if (tmp1 != 0)
        y |= tmp1 - 1;
}
}
