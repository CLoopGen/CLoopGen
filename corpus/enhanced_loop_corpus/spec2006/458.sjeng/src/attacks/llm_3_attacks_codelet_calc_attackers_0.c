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
    // Variant 2: Indirect memory access via precomputed index array
    // Use an auxiliary array of offsets to simulate indirect access pattern
    static const int directions[4][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };
    for (i = 0; i < 4; i++) {
        int found = 0;
        a_sq = square + rook_o[i];
        if (board[a_sq] == 5) {
            attackers++;
            break;
        } else if (board[a_sq] != 0) {
            // Traverse up to 4 steps using indirect offset indexing
            for (int step = 0; step < 4; step++) {
                int probe_idx = square + rook_o[i] * directions[i][step];
                if (board[probe_idx] == 7 || board[probe_idx] == 9) {
                    attackers++;
                    found = 1;
                    break;
                } else if (board[probe_idx] != 13) {
                    break;
                }
            }
            if (found) break;
        }
    }
}
