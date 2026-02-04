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
    // Variant 2: Indirect Array Access via Lookup Table
    // Precomputed offsets table simulates indirect memory access pattern.
    // This avoids dynamic pointer arithmetic and uses a fixed access sequence.
    static const int max_steps = 8;
    static const int offsets[4][8] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {-1, -2, -3, -4, -5, -6, -7, -8},
        {12, 24, 36, 48, 60, 72, 84, 96},
        {-12, -24, -36, -48, -60, -72, -84, -96}
    };

    for (i = 0; i < 4; i++) {
        if (board[square + rook_o[i]] == 6) {
            attackers++;
            continue;
        }

        int found_queen_or_bishop = 0;
        for (int step = 0; step < max_steps; step++) {
            int candidate_sq = square + offsets[i][step];
            int piece = board[candidate_sq];

            if (piece == 0) continue;

            if (piece == 8 || piece == 10) {
                attackers++;
                found_queen_or_bishop = 1;
            }
            if (piece != 13) {
                break;
            }
        }
    }
}
