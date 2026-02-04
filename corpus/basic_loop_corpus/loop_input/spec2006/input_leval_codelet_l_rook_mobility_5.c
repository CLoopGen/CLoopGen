#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    // Initialize board with value 13 except the first few elements to control loop termination
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set square such that l starts near the end of the array and decrements safely
    square = 143;  // so l = square - 1 = 142
    m = 0;         // initialize counter

    // Ensure board[0] is not 13 to prevent out-of-bounds access when l goes below 0
    board[0] = 0;
}