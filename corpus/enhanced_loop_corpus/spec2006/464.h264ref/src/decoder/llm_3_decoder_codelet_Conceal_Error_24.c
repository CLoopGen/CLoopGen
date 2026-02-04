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
    // Variant 2: Memory Access Pattern Modification - Strided Access with Linear Indexing
    // Replace nested indexing with a strided linear traversal over block indices,
    // simulating a more cache-unfriendly but functionally equivalent access pattern.
    int idx = 0;
    const int blocks_per_side = 16 / 4;
    for (idx = 0; idx < blocks_per_side * blocks_per_side; idx++) {
        int block_x = idx % blocks_per_side;
        int block_y = idx / blocks_per_side;
        for (i = 0; i < 2; i++) {
            // Use strided access by flipping index order in tmp_mv to create non-consecutive memory fetches
            mv[i][block_y][block_x] = tmp_mv[mb_x * 4 + block_x + 4][(mb_y * 4 + block_y) + i][0]; // introduce stride in second dim
        }
    }
}
