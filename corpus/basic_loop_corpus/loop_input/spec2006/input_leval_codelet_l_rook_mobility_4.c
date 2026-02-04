#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize board: set most elements to 13 to allow loop iteration
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set square such that l starts at a valid index and can decrement by 12 multiple times
    // We want l = square - 12 to be within [0, 143], and we want several steps until l < 0
    // Choose square so that l starts near the top of the array and steps down by 12
    // Let's start l at 132 (so square = 144), then l goes: 132, 120, 108, ..., until >=0
    square = 144;
    
    // Ensure board[l] == 13 for all l in the path: indices 132, 120, ..., 12, 0
    // Our initialization already set all to 13, so safe

    // Set m to 0 initially, as it is being incremented
    m = 0;
}