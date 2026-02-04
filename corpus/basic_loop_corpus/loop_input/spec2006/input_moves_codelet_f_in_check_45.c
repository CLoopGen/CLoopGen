#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize board with size 144 as declared
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to allow loop to progress
    }

    // Ensure that bking_loc is set such that bking_loc + 12 is within bounds
    // and allows several iterations before going out of bounds or hitting a non-13 value.
    // We choose bking_loc near the start but leave room for increments by 12
    bking_loc = 0;

    // Modify one element beyond a few iterations to break the loop eventually
    // Let loop run about 10 times: stops when l reaches (bking_loc + 12*10 + 12) = 132
    if (bking_loc + 12 * 11 < 144) {
        board[bking_loc + 12 * 11] = 0;  // Stop condition after 11 steps
    }

    l = 0; // Initial value not critical as loop will overwrite it
}