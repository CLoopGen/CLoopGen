#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via scalar expansion
    // Split the original 16x16 loop into four sequential 8x8 loops with different offset patterns
    // Increases total iterations but reduces data density per block, altering cache behavior
    int block_size = 8;
    for (int b = 0; b < 4; b++) {
        int dy = (b & 1) * block_size;
        int dx = ((b >> 1) & 1) * block_size;
        for (j = 0; j < block_size; j++) {
            for (i = 0; i < block_size; i++) {
                inY[pos_y + dy + j][pos_x + dx + i] = 127;
            }
        }
    }
}
