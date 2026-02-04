#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int bishop_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access with Unrolled Checks
    int offsets[] = {bishop_o[0], bishop_o[1], bishop_o[2], bishop_o[3]};
    attackers = 0; // Reset attackers as side effect handling may vary
    for (i = 0; i < 4; i++) {
        a_sq = square + offsets[i];
        int piece = board[a_sq];
        
        if (piece == 2 && !(i % 2)) {
            attackers++;
            continue;
        }
        if (piece == 6) {
            attackers++;
            continue;
        }
        
        // Simulate up to 3 steps along the same direction without while
        for (int step = 1; step <= 3; step++) {
            a_sq += offsets[i]; // Move further in same direction
            piece = board[a_sq];
            
            if (piece == 12 || piece == 10) {
                attackers++;
                break;
            } else if (piece != 13) {
                break;
            }
            // If empty (0), loop ends naturally
        }
    }
}
