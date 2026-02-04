#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern Intersection initial_board[421];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling (stride-1 access pattern)
    int size = 19 + 1;
    int limit = (19 + 2) * (19 + 1) + 1;
    for (k = 0; k < limit; k += 4) {
        // Unroll 4 iterations: process k, k+1, k+2, k+3 if within bounds
        for (int j = 0; j < 4; j++) {
            int idx = k + j;
            if (idx >= limit) break;
            int row = idx / size - 1;
            int col = idx % size - 1;
            if (!((unsigned int)(row) < (unsigned int)board_size && (unsigned int)(col) < (unsigned int)board_size)) {
                board[idx] = 3;
                initial_board[idx] = 3;
            }
        }
    }
}
