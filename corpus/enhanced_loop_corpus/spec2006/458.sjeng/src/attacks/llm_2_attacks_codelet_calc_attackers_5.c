#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int knight_o[8];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing knight_o[0..7] sequentially, access with a stride of 2 (then handle wrap-around)
    int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Interleaved even-odd indexing to create strided access pattern
    for (i = 0; i < 8; i++) {
        a_sq = square + knight_o[indices[i]];
        if (board[a_sq] == 4)
            attackers++;
    }
}
