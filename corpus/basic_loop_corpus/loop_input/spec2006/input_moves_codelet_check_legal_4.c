#include <stdio.h>
#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 for most elements to allow loop traversal
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }

    // Set a boundary condition: ensure that at some point board[l] != 13 to break the loop
    // We'll set an element along the decrement path (l -= 13) to a different value
    // Choose bking_loc such that initial l = bking_loc - 13 is within bounds
    // and the sequence l -= 13 eventually hits a non-13 value.

    // Pick a safe location: let's start near the end of the array
    bking_loc = 143;  // so l starts at 130
    // Now, set an element before 130 (in steps of 13) to break the loop
    // Sequence: 130, 117, 104, 91, 78, 65, 52, 39, 26, 13, 0
    // We'll break at l=0 by setting board[0] to something else
    board[0] = 0;

    // Ensure bking_loc is valid: 143 is within [0,143]
    // Initial l = 130, which is valid index
}