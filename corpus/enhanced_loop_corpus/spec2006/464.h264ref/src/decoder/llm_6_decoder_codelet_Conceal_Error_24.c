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
    int temp_i, temp_block_y, temp_block_x;
    for (temp_block_y = 0; temp_block_y < (16 / 4); temp_block_y++)
        for (temp_block_x = 0; temp_block_x < (16 / 4); temp_block_x++)
            for (temp_i = 0; temp_i < 2; temp_i++) {
                int src_y = mb_y * 4 + temp_block_y;
                int src_x = mb_x * 4 + temp_block_x;
                mv[temp_i][temp_block_y][temp_block_x] = tmp_mv[src_x + 4][src_y][temp_i];
            }
}
