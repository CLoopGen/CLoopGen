#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize board with size 144 as declared
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;  // Set all elements to 13 to allow loop progression
    }

    // Ensure that bking_loc is set such that l starts at bking_loc + 13
    // and stays within bounds during loop execution.
    // We want the loop to run for a significant number of iterations but not overflow.
    // Since l += 13 each time, we need to control when it exits.

    // To avoid out-of-bounds access, we must ensure l < 144 at all times.
    // The loop condition checks board[l] == 13, so we can break it by setting one element not equal to 13.
    // Let's set the last few elements to break the loop safely.

    // Keep most of the chain valid, but terminate before buffer end
    board[143] = 0; // This will be hit when l reaches 143, breaking the loop

    // Set bking_loc so that initial l = bking_loc + 13 is near the start
    // and can advance in steps of 13 until approaching 143.
    // We want: l = bking_loc + 13, then l += 13 repeatedly.
    // Choose bking_loc such that sequence doesn't overshoot.

    // Try to maximize iterations without exceeding bounds.
    // Largest starting l should be <= 142, and stepping by 13.
    // Find maximum chain length: positions: s, s+13, s+26, ..., < 143

    // Let’s set bking_loc = 0 -> l starts at 13
    bking_loc = 0;

    // Now the loop will start at l=13, then 26, 39, ..., up to 130, 143 -> but 143 has value 0
    // So when l=143, board[l]==0 != 13 -> loop stops. Safe and valid.
}