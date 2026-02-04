#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sb_sample_f[16][2][8];
extern int blocks;
extern int blk;
extern int sb;
extern int32_t sb_sample_j[16][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp0, temp1;
    for (blk = 0; blk < blocks; blk++) {
        temp0 = sb_sample_j[blk][0];
        temp1 = sb_sample_j[blk][1];
        sb_sample_f[blk][0][sb] = temp0;
        sb_sample_f[blk][1][sb] = temp1;
    }
}
