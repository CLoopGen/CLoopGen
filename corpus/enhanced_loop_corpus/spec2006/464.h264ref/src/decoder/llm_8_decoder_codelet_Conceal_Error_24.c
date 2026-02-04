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
    // Variant 1: Increased computational intensity with unrolled inner operations and doubled effective trip count
    // by splitting the i-loop into two explicit assignments, increasing arithmetic density.
    for (block_y = 0; block_y < (16 / 4); block_y++)
        for (block_x = 0; block_x < (16 / 4); block_x++) {
            int idx_x = mb_x * 4 + block_x + 4;
            int idx_y = mb_y * 4 + block_y;
            mv[0][block_y][block_x] = tmp_mv[idx_x][idx_y][0];
            mv[1][block_y][block_x] = tmp_mv[idx_x][idx_y][1];
        }
}
