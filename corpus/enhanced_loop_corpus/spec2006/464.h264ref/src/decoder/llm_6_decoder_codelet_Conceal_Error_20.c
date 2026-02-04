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
    int block_y, block_x, i;
    for (block_y = 0; block_y < (16 / 4); block_y++)
        for (block_x = 0; block_x < (16 / 4); block_x++)
            for (i = 0; i < 2; i++) {
                int temp_val = tmp_mv[mb_x * 4 + block_x + 4][mb_y * 4 + block_y][i];
                mv[i][block_y][block_x] = temp_val;
            }
}
