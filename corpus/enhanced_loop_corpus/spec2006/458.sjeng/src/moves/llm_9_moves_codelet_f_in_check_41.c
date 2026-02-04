#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other iteration through step adjustment
    // and introduce a nested structure with controlled inner iterations
    for (l = bking_loc + 13; board[l] == 13; l += 26) {
        for (int j = 0; j < 2 && (l - 13 + j) < 144; ++j) {
            if (board[l - 13 + j] == 13) {
                // Simulate partial original behavior with bounded auxiliary computation
                board[l - 13 + j] ^= 1;
            }
        }
    }
}
