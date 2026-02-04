#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except for a sentinel
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set a boundary condition to stop the loop: place a non-13 value
    // Choose wking_loc so that l starts at wking_loc + 12 and walks through valid indices
    wking_loc = 0;  // Start from beginning

    // Ensure that the loop will terminate by setting a non-13 value at the last position we might reach
    // The loop steps by 12, starting at wking_loc + 12 = 12, then 24, 36, ...
    // We need to break the loop before going out of bounds.
    // Let's set board[132] to something other than 13 (e.g., 0) so loop stops at l=132
    board[132] = 0;

    // This ensures that the loop runs: l = 12, 24, 36, ..., 120, then at l=132, board[l]==0 -> exits
}