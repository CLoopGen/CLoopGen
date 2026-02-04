#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    // Initialize the board array with value 13 except for a boundary condition
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    // Set up bking_loc so that the loop starts near the middle or upper end of the column
    // Since the loop steps by -12 (assumed to be vertical moves on a 12x12 board),
    // we choose bking_loc such that l = bking_loc - 12 is within [0,143], and stepping down by 12s is safe

    // Choose bking_loc at the bottom of a column (e.g., row 11) to allow multiple iterations
    // Let’s assume 12x12 layout: indices 0..11, 12..23, ..., 132..143
    // Pick a column, say column 5, and start from row 11 -> index = 11*12 + 5 = 137
    // Then bking_loc = 137 + 12 = 149 would make l start at 137
    // But board size is only 144, so we must not exceed 143.

    // Instead, let bking_loc = 137 + 12 = 149 is invalid. So set bking_loc within valid range.

    // We want l = bking_loc - 12 to be a valid index, so bking_loc must be >= 12
    // Also, during the loop, l -= 12 repeatedly while board[l]==13

    // To prevent out-of-bounds, we need to break before l < 0.
    // So place a non-13 value at the top of the column to stop early.

    // Reset some positions in the column to break the loop after several iterations
    // Use column index 5: indices 5, 17, 29, ..., 137
    // Set all to 13 except the first one (index 5) to something else
    for (int row = 1; row < 12; row++) {
        int idx = row * 12 + 5;
        board[idx] = 13;
    }
    board[5] = 0; // stopping condition at top

    // Now set bking_loc so that we start at bottom and traverse upward
    bking_loc = 137 + 12; // so l starts at 137

    // This will cause loop to run for 11 iterations (from 137 down to 17, then 5 fails)
}