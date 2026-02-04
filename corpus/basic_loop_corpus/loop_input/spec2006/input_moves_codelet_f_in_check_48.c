#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array
    for (int i = 0; i < 144; i++) {
        board[i] = 13;  // Set all elements to 13 to satisfy loop condition initially
    }

    // Ensure loop termination by setting a boundary
    // Choose bking_loc such that when l decrements from bking_loc - 1, it eventually hits an index where board[l] != 13
    // We'll set board[0] to a different value to stop the loop
    board[0] = 0;

    // Set bking_loc near the end of the array to allow long traversal
    bking_loc = 144;  // So l starts at 143 and decrements until it hits 0

    // Initialize l to avoid undefined behavior if used before loop
    l = bking_loc;
}