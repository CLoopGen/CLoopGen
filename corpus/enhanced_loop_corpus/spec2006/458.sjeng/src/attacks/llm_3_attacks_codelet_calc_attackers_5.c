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
    // Variant 2: Consecutive and Local Buffer-Based Access
    // Pre-load knight offsets into a local consecutive buffer to improve spatial locality
    int local_knight_o[8];
    for (int j = 0; j < 8; j++) {
        local_knight_o[j] = knight_o[j];
    }
    // Now use the local copy with sequential, predictable access
    for (i = 0; i < 8; i++) {
        a_sq = square + local_knight_o[i];
        if (board[a_sq] == 4)
            attackers++;
    }
}
