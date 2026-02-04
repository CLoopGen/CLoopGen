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
    // Variant 2: Indirect memory access using an index remapping table
    // Introduce an explicit indirection array to simulate irregular access pattern
    const int index_map[8] = {2, 6, 1, 7, 0, 4, 3, 5}; // Arbitrary permutation
    attackers = 0;
    for (int i = 0; i < 8; i++) {
        int mapped_idx = index_map[i];           // Indirect indexing into knight_o
        a_sq = square + knight_o[mapped_idx];   // Strided/indirect access via remapped index
        if (board[a_sq] == 3)
            attackers++;
    }
}
