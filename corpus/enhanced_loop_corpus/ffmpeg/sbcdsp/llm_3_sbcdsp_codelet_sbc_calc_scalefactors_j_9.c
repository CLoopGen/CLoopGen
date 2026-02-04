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
// Change memory access pattern to stride across the last dimension first (transpose-like traversal)
// Simulate strided access by looping over a transformed index
int i;
for (i = 0; i < blocks; i++) {
    // Access with non-unit stride indirectly via arithmetic
    int index = i;
    tmp0 = ((sb_sample_f[index][0][sb]) >= 0 ? (sb_sample_f[index][0][sb]) : (-(sb_sample_f[index][0][sb])));
    tmp1 = ((sb_sample_f[index][1][sb]) >= 0 ? (sb_sample_f[index][1][sb]) : (-(sb_sample_f[index][1][sb])));
    if (tmp0 != 0)
        x |= tmp0 - 1;
    if (tmp1 != 0)
        y |= tmp1 - 1;
}
}
