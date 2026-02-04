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

    // Set square such that l starts at a valid index and can decrement by 11 multiple times
    // We want l = square - 11 to be within bounds [0, 143], and allow several decrements
    // Choose square so that initial l is near the upper end but allows stepping back by 11
    // To avoid out-of-bounds, ensure l >= 0 after each step

    // Max starting l: 143. We need l -= 11 repeatedly. Let's allow about 10 steps -> need l ~ 110
    // So set square - 11 = 121 => square = 132
    square = 132;

    // Re-validate: l starts at 121, then 110, 99, ..., until below 13
    // board[121], board[110], ... are all 13 -> loop runs

    // Ensure board values along diagonal (l -= 11) are 13
    for (int idx = 121; idx >= 11; idx -= 11) {
        board[idx] = 13;
    }
    // Stop before idx < 11 to prevent invalid access

    // One past the last valid index in sequence should break condition
    if (121 - 11 * 12 >= 0) {
        board[121 - 11 * 12] = 0; // Ensures loop eventually stops
    } else {
        board[0] = 0;
    }

    // Initialize m to 0 for counting
    m = 0;
}