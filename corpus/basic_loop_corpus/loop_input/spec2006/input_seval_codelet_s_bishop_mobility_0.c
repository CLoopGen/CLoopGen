#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize the board array with value 13 to allow the loop condition `board[l] == 13` to be true
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }

    // Set square such that l starts at a valid index and can decrement by 13 multiple times
    // We want l = square - 13 to be within [0, 143], and we want several iterations before going out of bounds
    // Choose square so that l starts near the upper end of the array
    // To ensure we don't go below 0 too quickly, let’s start l at 130 (so square = 143)
    // Then l will take values: 130, 117, 104, ..., until it goes below 0
    square = 143;
    l = square - 13;  // initial value used in loop condition

    // Ensure that l is within bounds
    if (l >= 144 || l < 0) {
        l = 0;
    }

    // Initialize m to 0 as it's being incremented in the loop
    m = 0;
}