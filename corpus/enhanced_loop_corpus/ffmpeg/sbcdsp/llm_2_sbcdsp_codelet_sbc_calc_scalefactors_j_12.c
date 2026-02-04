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
    // Variant 1: Consecutive memory access by reordering loops and using linear indexing
    // We unroll the fixed inner dimension [2] into consecutive accesses to improve spatial locality
    int32_t (*base_f)[16][2][8] = &sb_sample_f;
    for (blk = 0; blk < blocks; blk++) {
        int32_t *f_left = (*base_f)[blk][0];
        int32_t *f_right = (*base_f)[blk][1];
        int32_t *j_left = sb_sample_j[blk];
        f_left[sb] = j_left[0];
        f_right[sb] = j_left[1];
    }
}
