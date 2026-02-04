#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int dpos;
int surrounded;
int color;
int other;
char mf[400];
char mn[400];

void init_vars() {
    // Initialize scalar variables
    dpos = 0;
    surrounded = 1;
    color = 1;
    other = 2;

    // Initialize mf and mn arrays to enable controlled traversal
    for (int i = 0; i < 400; i++) {
        mf[i] = 1;
        mn[i] = 0;
    }

    // Initialize board array with safe default values
    // Board size is 421, which suggests a padded 19x19 grid (19*19 = 361), so we zero-initialize up to 421
    for (int i = 0; i < 421; i++) {
        board[i] = 0;
    }

    // Set boundary regions to 3 (invalid) to prevent out-of-bound-like behavior in stencil checks
    // Simulate a border of invalid cells around the logical grid
    const int GRID_SIZE = 19;
    const int STRIDE = (19 + 2); // 21, assuming padding on top/bottom

    // Mark off-grid positions as 3
    for (int i = 0; i < 21; i++) {
        if (i < 421) board[i] = 3; // Top padding row
        int bottom_idx = 20 * STRIDE + i;
        if (bottom_idx < 421) board[bottom_idx] = 3;
    }
    for (int row = 0; row < 20; row++) {
        int idx1 = row * STRIDE;
        int idx2 = row * STRIDE + 20;
        if (idx1 < 421) board[idx1] = 3;     // Left padding
        if (idx2 < 421) board[idx2] = 3;     // Right padding
    }

    // Initialize inner 19x19 grid (logical area from index 21+1 to ...)
    for (int row = 1; row <= 19; row++) {
        for (int col = 1; col <= 19; col++) {
            int idx = row * STRIDE + col;
            if (idx < 421) {
                board[idx] = 0;
            }
        }
    }

    // Place some test patterns to trigger conditionals without immediate out-of-bounds
    // Ensure center region allows the loop to run many iterations before exiting
    for (int i = 21 + 2; i < 400 && i < (19 + 1) * (19 + 1); i++) {
        if (mf[i]) {
            // Create vertical and horizontal neighbors that may satisfy conditional branches
            if ((i % 21) >= 3 && (i % 21) <= 18 && (i / 21) >= 3 && (i / 21) <= 18) {
                // Inner safe zone: set up potential matches
                int up = i - 21;
                int down = i + 21;
                int left = i - 1;
                int right = i + 1;

                if (up > 21 && board[up] != 3) board[up] = 0;
                if (down < 421 && board[down] != 3) board[down] = 0;
                if (left > 0 && board[left] != 3) board[left] = 0;
                if (right < 421 && board[right] != 3) board[right] = 0;

                // Set double-offset positions to 'color' where needed
                if (up - 21 > 0) { board[up - 21] = color; mn[up - 21] = 0; }
                if (down + 21 < 421) { board[down + 21] = color; mn[down + 21] = 0; }
                if (left - 1 > 0) { board[left - 1] = color; mn[left - 1] = 0; }
                if (right + 1 < 421) { board[right + 1] = color; mn[right + 1] = 0; }
            }
        }
    }

    // Ensure loop starts correctly
    dpos = (19 + 2);
    surrounded = 1;
}