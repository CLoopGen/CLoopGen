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
    int temp_attackers = 0;
    int offsets[4];
    int valid_path[4] = {1, 1, 1, 1};

    // Precompute offsets to eliminate repeated memory access and introduce WAW dependency via array
    for (i = 0; i < 4; i++) {
        offsets[i] = square + rook_o[i];
    }

    for (i = 0; i < 4; i++) {
        int a_sq_local = offsets[i];
        int piece = board[a_sq_local];

        if (piece == 6) {
            temp_attackers++;
            valid_path[i] = 0; // WAW-like update to flag array, no actual loop-carried dep
        } else if (piece != 0) {
            if (piece == 8 || piece == 10) {
                temp_attackers++;
            } else if (piece == 13) {
                a_sq_local += rook_o[i];
                if (board[a_sq_local] != 0 && (board[a_sq_local] == 8 || board[a_sq_local] == 10)) {
                    temp_attackers++;
                }
            }
        }
    }

    attackers += temp_attackers; // Accumulate non-loop-carried result
}
