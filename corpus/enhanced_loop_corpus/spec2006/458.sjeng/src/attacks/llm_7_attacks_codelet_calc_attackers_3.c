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
    int local_a_sq;
    int has_attacker = 0;

    // Introduce loop-carried dependency via `has_attacker` to prevent further iterations once set
    for (i = 0; i < 4 && !has_attacker; i++) {
        local_a_sq = square + rook_o[i];

        if (board[local_a_sq] == 6) {
            attackers++;
            has_attacker = 1;
        } else if (board[local_a_sq] != 0) {
            if (board[local_a_sq] == 8 || board[local_a_sq] == 10) {
                attackers++;
                has_attacker = 1;
            } else if (board[local_a_sq] == 13) {
                int next_sq = local_a_sq + rook_o[i];
                if (board[next_sq] == 8 || board[next_sq] == 10) {
                    attackers++;
                    has_attacker = 1;
                }
            }
        }
    }

    // Eliminate any RAW hazards by ensuring all reads happen before conditional side effects
    // Loop-carried dependency introduced via control flow (early exit), not data
}
