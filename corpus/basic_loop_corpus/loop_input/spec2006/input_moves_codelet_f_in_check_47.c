#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize bking_loc to a valid starting index within [0, 143]
    bking_loc = 0;

    // Fill board with value 13 up to just before the last few elements
    for (int i = 0; i < 143; i++) {
        board[i] = 13;
    }
    // Set a non-13 value at the end to stop the loop and prevent out-of-bounds
    board[143] = 0;
}