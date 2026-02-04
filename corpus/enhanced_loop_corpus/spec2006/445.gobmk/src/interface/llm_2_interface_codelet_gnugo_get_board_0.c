#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int b[19][19];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D iteration into a 1D stride
    // We traverse the board array in consecutive order, computing i and j from a linear index
    int idx = 0;
    for (int linear = 0; linear < board_size * board_size; linear++) {
        int i = linear / board_size;
        int j = linear % board_size;
        b[i][j] = board[(19 + 2) + i * (19 + 1) + j];
    }
}
