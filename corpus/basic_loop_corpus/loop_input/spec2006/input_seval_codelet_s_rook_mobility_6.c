#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize the board array: set most elements to 13 to allow loop to iterate
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    
    // Set square such that l starts at square + 1
    // We want to avoid out-of-bounds access: l must be < 144 when accessing board[l]
    // So we require square + 1 < 144 -> square <= 141
    // Choose square = 100 to allow 43 iterations (from 101 to 143 inclusive)
    square = 100;

    // Initialize l and m before loop; though loop updates l, m should start at 0
    l = 0;
    m = 0;
}