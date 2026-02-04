#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern  int knight_o[8];
extern int square;
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Array Access via Pointer Arithmetic
    // Use pointer arithmetic to traverse knight_o and board indirectly
    const int* k_ptr = knight_o;
    m = 0;
    for (d = 0; d < 8; d++) {
        int offset = *(k_ptr + d);          // Indirect access through pointer
        if (*(board + square + offset) == 13) // Indirect access in board
            m++;
    }
}
