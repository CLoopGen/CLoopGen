#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int rook_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access with Unrolled Sequential Checks
    // Instead of using a while loop, we unroll a fixed number of steps based on known stride (rook_o[i])
    // and replace the inner loop with direct conditional checks in a for-loop.
    for (i = 0; i < 4; i++) {
        a_sq = square + rook_o[i];
        if (board[a_sq] == 6) {
            attackers++;
            continue;
        }
        // Simulate up to 8 steps along the ray (typical chess board limit)
        for (int step = 1; step <= 8; step++) {
            int next_sq = square + rook_o[i] * step;
            if (board[next_sq] == 0) {
                // Empty square, keep going
                continue;
            }
            if (board[next_sq] == 8 || board[next_sq] == 10) {
                attackers++;
                break;
            }
            if (board[next_sq] != 13) {
                break;
            }
        }
    }
}
