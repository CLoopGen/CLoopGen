#include <stdio.h>

#include <inttypes.h>

extern int mb_y;
extern int mb_x;
extern int i;
extern int block_x;
extern int block_y;
extern int mv[2][4][4];
extern short ***tmp_mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with collapsed loops and increased stride
    // Combines block_x and block_y into a single loop with larger step size, reducing total iterations.
    // Only processes every other block, effectively lowering workload.
    for (i = 0; i < (16 / 4) * (16 / 4); i += 2) {  // Half the number of iterations due to step=2
        block_y = (i / 4) % 4;
        block_x = (i % 4) * 2;  // Stride of 2 in block_x reduces coverage
        if (block_x >= 4) continue;  // Skip out-of-bound accesses
        mv[0][block_y][block_x] = tmp_mv[mb_x * 4 + block_x + 4][mb_y * 4 + block_y][0];
        mv[1][block_y][block_x] = tmp_mv[mb_x * 4 + block_x + 4][mb_y * 4 + block_y][1];
    }
}
