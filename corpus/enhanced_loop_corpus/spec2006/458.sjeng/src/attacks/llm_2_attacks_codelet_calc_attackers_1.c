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
    // Variant 1: Strided Memory Access with Unrolled Sequential Checks
    // Instead of using a while loop, we unroll the traversal up to a fixed depth (e.g., 3 steps)
    // and use strided access based on bishop_o[i]. This changes memory access pattern to predictable stride.
    for (i = 0; i < 4; i++) {
        a_sq = square + bishop_o[i];
        if (board[a_sq] == 1 && (i % 2)) {
            attackers++;
            continue;
        } else if (board[a_sq] == 5) {
            attackers++;
            continue;
        } else if (board[a_sq] == 0) {
            // Begin strided traversal in the direction of bishop_o[i]
            int next1 = a_sq + bishop_o[i];
            int next2 = next1 + bishop_o[i];
            int next3 = next2 + bishop_o[i];

            // Check up to 3 consecutive strides without using while
            if (board[next1] != 0) {
                if (board[next1] == 11 || board[next1] == 9) {
                    attackers++;
                    continue;
                } else if (board[next1] != 13) continue;
                if (board[next2] != 0) {
                    if (board[next2] == 11 || board[next2] == 9) {
                        attackers++;
                        continue;
                    } else if (board[next2] != 13) continue;
                    if (board[next3] != 0) {
                        if (board[next3] == 11 || board[next3] == 9) {
                            attackers++;
                        }
                    }
                }
            }
        }
    }
}
