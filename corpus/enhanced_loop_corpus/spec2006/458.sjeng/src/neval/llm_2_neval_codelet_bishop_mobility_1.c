#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;
extern int diridx;
extern  int dir[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided access with fixed stride over a flattened structure
    // Instead of using dir[diridx] for direction, we use a fixed stride pattern (e.g., ±12, ±1) to simulate row/column traversal
    int strides[4] = {1, -1, 12, -12}; // Assume 12x12 board: horizontal and vertical strides
    for (diridx = 0; diridx < 4; diridx++) {
        int stride = strides[diridx];
        for (l = square + stride; board[l] == 13; l += stride)
            m++;
    }
}
