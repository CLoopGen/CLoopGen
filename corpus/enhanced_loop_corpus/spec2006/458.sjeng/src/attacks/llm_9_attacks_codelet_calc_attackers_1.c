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
    // Variant 2: Reduced trip count with expanded condition checks per iteration
    // Only 2 iterations (half the original), but each performs multiple directional checks
    // Eliminates while by precomputing up to two steps along the direction
    attackers = 0;
    for (i = 0; i < 2; i++) {
        int offset1 = bishop_o[i * 2];
        int offset2 = bishop_o[i * 2 + 1];

        // Check first direction (even index)
        a_sq = square + offset1;
        if ((board[a_sq] == 1 && (i * 2) % 2) || board[a_sq] == 5) {
            attackers++;
        } else if (board[a_sq] != 0) {
            int next_a_sq = a_sq + offset1;
            if (board[next_a_sq] == 11 || board[next_a_sq] == 9) {
                attackers++;
            } else if (board[next_a_sq] == 13) {
                int final_sq = next_a_sq + offset1;
                if (final_sq >= 0 && final_sq < 144 && (board[final_sq] == 11 || board[final_sq] == 9)) {
                    attackers++;
                }
            }
        }

        // Check second direction (odd index)
        a_sq = square + offset2;
        if ((board[a_sq] == 1 && (i * 2 + 1) % 2) || board[a_sq] == 5) {
            attackers++;
        } else if (board[a_sq] != 0) {
            int next_a_sq = a_sq + offset2;
            if (board[next_a_sq] == 11 || board[next_a_sq] == 9) {
                attackers++;
            } else if (board[next_a_sq] == 13) {
                int final_sq = next_a_sq + offset2;
                if (final_sq >= 0 && final_sq < 144 && (board[final_sq] == 11 || board[final_sq] == 9)) {
                    attackers++;
                }
            }
        }
    }
}
