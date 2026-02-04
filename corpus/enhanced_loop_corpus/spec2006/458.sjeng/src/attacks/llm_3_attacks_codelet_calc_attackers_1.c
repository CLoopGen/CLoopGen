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
    // Variant 2: Indirect Memory Access via Precomputed Index Array
    // Use an auxiliary array of precomputed offsets to simulate indirect addressing
    // This changes access pattern from direct indexing to indirect via offset table
    const int max_steps = 3;
    int offsets[4][3];  // Precomputed traversal offsets for each direction

    // Precompute indirect access indices
    for (int dir = 0; dir < 4; dir++) {
        for (int step = 0; step < max_steps; step++) {
            offsets[dir][step] = square + bishop_o[dir] * (step + 1);
        }
    }

    for (i = 0; i < 4; i++) {
        a_sq = square + bishop_o[i];
        if (board[a_sq] == 1 && (i % 2)) {
            attackers++;
            continue;
        } else if (board[a_sq] == 5) {
            attackers++;
            continue;
        } else if (board[a_sq] != 0) {
            // Use indirect access through precomputed offsets
            int val1 = board[offsets[i][0]];
            if (val1 != 0) {
                if (val1 == 11 || val1 == 9) {
                    attackers++;
                    continue;
                } else if (val1 != 13) continue;

                int val2 = board[offsets[i][1]];
                if (val2 != 0) {
                    if (val2 == 11 || val2 == 9) {
                        attackers++;
                        continue;
                    } else if (val2 != 13) continue;

                    int val3 = board[offsets[i][2]];
                    if (val3 != 0) {
                        if (val3 == 11 || val3 == 9) {
                            attackers++;
                        }
                    }
                }
            }
        }
    }
}
