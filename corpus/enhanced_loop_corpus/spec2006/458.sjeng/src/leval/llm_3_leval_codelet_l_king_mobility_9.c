#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int king_o[8];
extern int d;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using pointer arithmetic and auxiliary index array
    // Simulates irregular access via precomputed offsets stored in a local array
    const int *idx[8] = { &king_o[0], &king_o[1], &king_o[2], &king_o[3],
                          &king_o[4], &king_o[5], &king_o[6], &king_o[7] };
    int base = square;
    for (d = 0; d < 8; d++) {
        if (board[base + *idx[d]] == 13)
            m++;
    }
}
