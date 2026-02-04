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
    // Variant 2: Memory Access Pattern Modification - Strided Access with Reverse Traversal
    int rev_x, rev_y;
    for (block_y = 0; block_y < (16 / 4); block_y++) {
        rev_y = (16 / 4) - 1 - block_y; // reverse y index
        for (block_x = 0; block_x < (16 / 4); block_x++) {
            rev_x = (16 / 4) - 1 - block_x; // reverse x index
            for (i = 0; i < 2; i += 2) { // unroll-like access, strided by 2
                if (i < 2) {
                    mv[i][rev_y][rev_x] = tmp_mv[mb_x * 4 + rev_x + 4][mb_y * 4 + rev_y][i];
                }
            }
        }
    }
}
