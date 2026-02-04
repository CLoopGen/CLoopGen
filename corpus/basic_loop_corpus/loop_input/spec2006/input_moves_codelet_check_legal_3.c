#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except the last element
    for (int i = 0; i < 143; i++) {
        board[i] = 13;
    }
    // Set a sentinel value to break the loop
    board[143] = 0;

    // Ensure bking_loc is set such that l starts at bking_loc + 1 and remains within bounds
    bking_loc = 0;  // So l starts at 1, and we can safely increment until hitting 143
}