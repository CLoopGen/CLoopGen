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
    // Variant 1: Increased trip count with unrolled inner logic and reduced arithmetic operations
    // Trip count increased to 8 (simulating more directions), no while loops, flattened conditions
    attackers = 0;  // Reset attackers for realism
    for (i = 0; i < 8; i++) {
        a_sq = square + bishop_o[i % 4];  // Reuse original offsets cyclically

        // Directly check exit conditions using if-else ladder without loops
        if (board[a_sq] == 1 && (i % 2)) {
            attackers++;
        } else if (board[a_sq] == 5) {
            attackers++;
        } else if (board[a_sq] != 0) {
            int next_sq = a_sq + bishop_o[i % 4];
            // Simulate one step deeper in the ray (unrolling one iteration of the original while)
            if (board[next_sq] == 11 || board[next_sq] == 9) {
                attackers++;
            } else if (board[next_sq] != 13) {
                // Non-sliding piece or empty, no further propagation
            } else {
                int next_next_sq = next_sq + bishop_o[i % 4];
                if (board[next_next_sq] == 11 || board[next_next_sq] == 9) {
                    attackers++;
                }
            }
        }
    }
}
