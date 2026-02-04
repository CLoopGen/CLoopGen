#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern  int rook_o[4];
extern int a_sq;
extern int i;
extern int attackers;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with unrolled conditional checks
    // Instead of using a while loop, we unroll the traversal up to a fixed depth (4 steps)
    for (i = 0; i < 4; i++) {
        a_sq = square + rook_o[i];
        if (board[a_sq] == 5) {
            attackers++;
            break;
        } else if (board[a_sq] != 0) {
            // Simulate movement along the ray using fixed stride without while
            int next1 = a_sq + rook_o[i];
            int next2 = next1 + rook_o[i];
            int next3 = next2 + rook_o[i];
            int next4 = next3 + rook_o[i];

            if (board[next1] == 7 || board[next1] == 9) {
                attackers++;
                break;
            } else if (board[next1] != 13) {
                continue;
            }
            else if (board[next2] == 7 || board[next2] == 9) {
                attackers++;
                break;
            } else if (board[next2] != 13) {
                continue;
            }
            else if (board[next3] == 7 || board[next3] == 9) {
                attackers++;
                break;
            } else if (board[next3] != 13) {
                continue;
            }
            else if (board[next4] == 7 || board[next4] == 9) {
                attackers++;
                break;
            }
        }
    }
}
