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
    int dep_buffer[2]; // Introduce temporary buffer to create artificial WAW and RAW dependencies
    for (block_y = 0; block_y < (16 / 4); block_y++) {
        for (block_x = 0; block_x < (16 / 4); block_x++) {
            // Artificially create loop-carried dependency via reuse of dep_buffer
            for (i = 0; i < 2; i++) {
                short val = tmp_mv[mb_x * 4 + block_x + 4][mb_y * 4 + block_y][i];
                dep_buffer[i] = val; // Write to buffer (WAW if unrolled, RAW in next use)
            }
            // Ensure dependency by using buffer in second loop iteration
            if ((block_y * (16/4) + block_x) > 0) {
                mv[0][block_y][block_x] += dep_buffer[0]; // RAW: use after write
                mv[1][block_y][block_x] += dep_buffer[1];
            } else {
                mv[0][block_y][block_x] = dep_buffer[0];
                mv[1][block_y][block_x] = dep_buffer[1];
            }
        }
    }
}
