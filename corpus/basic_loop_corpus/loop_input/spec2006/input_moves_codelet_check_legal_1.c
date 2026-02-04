#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except for a sentinel
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set bking_loc such that l starts at bking_loc + 12
    // We want to avoid out-of-bounds access when incrementing by 12
    // Choose bking_loc so that we have a valid starting point and room to iterate
    bking_loc = 0;

    // Modify one element beyond the expected traversal path to break the loop
    // The loop checks board[l] == 13, so set a non-13 value to terminate
    // l starts at bking_loc + 12 = 12, then 24, 36, ...
    // Set board[132] to non-13 to break after several iterations (132 = 12*11)
    board[132] = 0;

    // Ensure l is initialized to a sane value before use, though loop sets it
    l = 0;
}